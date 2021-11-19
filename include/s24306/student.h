struct Student{
    std::string  name;
    std::string surname;
    int index_num;
    int current_term;
    double mean_grades;
   
    std::string const to_string();
};

std::string const Student::to_string(){
        return "Name: " + name + '\n'
                +"Surname: " + surname + '\n'
                + "Index: " + std::to_string(index_num) + '\n'
                + "Term: " + std::to_string(current_term) + '\n'
                + "Grades: " + std::to_string(mean_grades) + '\n';
    }
