#include <iostream>
class Node {
public:
    int coeff;
    int exp;
    Node* next;
    Node(int c, int e) : coeff(c), exp(e), next(nullptr) {}
};
class Polynomial {
private:
    Node* head;
public:
    Polynomial() : head(nullptr) {}
    void addTerm(int coeff, int exp) {
        Node* newNode = new Node(coeff, exp);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    void scanPolynomial() {
        int n, coeff, exp;
        std::cout << "Enter the number of terms in the polynomial: ";
        std::cin >> n;
        std::cout << "Enter the terms (coefficient, exponent) separated by space:\n";
        for (int i = 0; i < n; ++i) {
            std::cin >> coeff >> exp;
            addTerm(coeff, exp);
        }
    }
    Polynomial addPolynomials(const Polynomial& poly) {
        Polynomial result;
        Node* temp1 = head;
        Node* temp2 = poly.head;
        while (temp1 && temp2) {
            if (temp1->exp > temp2->exp) {
                result.addTerm(temp1->coeff, temp1->exp);
                temp1 = temp1->next;
            } else if (temp1->exp < temp2->exp) {
                result.addTerm(temp2->coeff, temp2->exp);
                temp2 = temp2->next;
            } else {
                result.addTerm(temp1->coeff + temp2->coeff, temp1->exp);
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        while (temp1) {
            result.addTerm(temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        while (temp2) {
            result.addTerm(temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
        return result;
    }
    void displayPolynomial() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->coeff << "x^" << temp->exp;
            temp = temp->next;
            if (temp) std::cout << " + ";
        }
        std::cout << std::endl;
    }
    ~Polynomial() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    Polynomial poly1, poly2, result;
    std::cout << "Enter details of polynomial 1:\n";
    poly1.scanPolynomial();
    std::cout << "Enter details of polynomial 2:\n";
    poly2.scanPolynomial();
    std::cout << "Polynomial 1: ";
    poly1.displayPolynomial();
    std::cout << "Polynomial 2: ";
    poly2.displayPolynomial();
    result = poly1.addPolynomials(poly2);
    std::cout << "Resultant polynomial (Polynomial 1 + Polynomial 2): ";
    result.displayPolynomial();
    return 0;
}
