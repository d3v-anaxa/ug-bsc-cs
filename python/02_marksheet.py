def get_total_marks(marks : dict) -> int:
    total = 0
    for subj in marks:
        total += marks[subj]
    return total


def get_percentage(total_marks: int) -> float:
    FULL_MARKS = 300
    percentage = total_marks / FULL_MARKS * 100
    return percentage

def get_grade(percentage : float) -> str:
    if(percentage >= 80):
        return "A"
    elif (percentage >= 70):
        return "B"
    elif (percentage >= 60):
        return "C"
    elif (percentage >= 40):
        return "D"
    else:
        return "E"

name = input("Enter name of student: ")
marks = {
        "English" : 0,
        "Math" : 0,
        "Science" : 0
        }
for subj in marks:
    marks[subj] = int(input("Enter marks in %s: " % subj))

total = get_total_marks(marks)
percentage = get_percentage(total)
grade = get_grade(percentage)

print(f" {name} | {total}/300 | %.2f%% | {grade}" % percentage)
