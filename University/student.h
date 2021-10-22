struct Student{
    std::string name{"Dawid"};
    std::string surname{"Hoffmeister"};
    int index_num{24306};
    int current_term{1};
    double mean_grades{5.0};

    std::string const to_string();
};

std::string const Student::to_string(){
        return "Name: " + name + '\n'
                + "Surname: " + surname + '\n'
                + "Index: " + std::to_string(index_num) + '\n'
                + "Term: " + std::to_string(current_term) + '\n'
                + "Grades: " + std::to_string(mean_grades) + '\n';
    }
