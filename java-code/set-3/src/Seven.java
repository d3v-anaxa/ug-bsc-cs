// WAP in with a child class inherits and accesses the only
// member function and only variable of the parrent class
// that has also been accessed from third part env

public class Seven {
	public static void main(String[] args){
		new Child("Jesus", "Joseph").displayInfo();
	}
}

class Parent {
	String parentName;
	Parent(String parentName){
		this.parentName = parentName;
	}
	
	public String getName(){
		return parentName;
	}
}

class Child extends Parent {
	String childName;

	Child(String childName, String parentName){
		super(parentName);
		this.childName = childName;
	}

	void displayInfo(){
		System.out.println("Child name : " + childName 
		+ " | Parent name : " + super.getName());
	}
}

// Output
// Child name : Jesus | Parent name : Joseph
