#include <string>

struct Person{
	std::string name;
	std::string surname;

	virtual std::string to_string() const = 0;

	Person(std::string inputName, std::string inputSurname){
	    name = inputName;
	    surname = inputSurname;
	}
};

struct Mr : Person{
	std::string to_string() const override{
		return ("Mr " + name);
	}

	Mr(std::string inputName, std::string inputSurname):Person(inputName, inputSurname){}
};

struct Mrs : Person{
	std::string to_string() const override{
        	return ("Mrs " + name);
	}

	Mrs(std::string inputName, std::string inputSurname):Person(inputName, inputSurname){}
};

struct Queen : Person{
	std::string to_string() const override{
        	return ("Queen " + name);
	}

	Queen(std::string inputName, std::string inputSurname):Person(inputName, inputSurname){}
};

struct King : Person{
	std::string to_string() const override{
	        return ("King " + name);
	}

	King(std::string inputName, std::string inputSurname):Person(inputName, inputSurname){}
};

std::string who_is_it(Person const& who){
        return who.to_string();
}

struct Greeting{
        virtual std::string greet(Person const& person) const = 0;
};

struct Hello : Greeting{
        std::string greet(Person const& person) const override{
                return ("Hello " + who_is_it(person) );
        }

	Hello() {};
};

struct Good_evening : Greeting{
	std::string greet(Person const& person) const override{
		return ("Good evening " + who_is_it(person) );
	}

	Good_evening() {};
};

struct Farewell : Greeting{
	std::string greet(Person const& person) const override{
		return ("Farewell " + who_is_it(person) );
	}

	Farewell() {};
};
