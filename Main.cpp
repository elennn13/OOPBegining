#include <iostream>
#include <string>

int main() {
	setlocale(LC_ALL, "ru");
	int n;
	
	class Student {
		    std::string name;
			int* marks;// динамический массив(через указатели*) оценок
			size_t marks_number;// количество оценок
			int age;

	public :// публичное, доступно за пределами классами
		Student() { // конструктор по умолчанию
			std::cout << "Конструктор по умолчанию.\n";
			name = "noname";
			marks = nullptr;
			marks_number = 0;
			age = 0;
		}

		Student(std::string other_name, int other_age = 0) {
			std::cout << "Параметрический конструктор.\n";
			name = other_name;
			marks = nullptr;
			marks_number = 0;
			setAge(other_age);
		}

		~Student() {
			std::cout << "Деструктор.\n"; // уничтожение объекта
				delete[1] marks;
		}

		void sayName() {// методы класса, действия которые может выполнять класс войдовский метод класса
		    std::cout << "My name is " << name << ".\n";
		}
		void setMark(int mark) {// метод ,свойство класса сеттер
			if (marks == nullptr) {
				marks = new int[1] {mark};// 1 оценка
				marks_number = 1;
				return;
			}
			int* tmp = new int[marks_number + 1];// увеличивает массив на +1
			for (size_t i = 0; i < marks_number; ++i)
				tmp[i] = marks[i];
			tmp[marks_number] = mark;// увеличили массив чтобы добавить новую оценку
			delete[] marks;
			marks = tmp;// перенаправления массива со старого на новый
			++marks_number;
		}
		int getMark(size_t index) {// позволяет получить значение поле класса (геттер класса)
			return marks[index];
		}
		void setAge(int other_age) {
			if (other_age >= 5 && other_age <= 55) {
				age = other_age;
				return;
			}
			age = 0;
		}
		int getAge() {
			return age;
		}
	};

	// Блок проверки деструктора
	if (true) {
		Student tmp;
	}

	Student s1("Tom Smith", 26);// Каждый раз когда вызывается объект, вызвыается конструктор
	// s1.name = "Tom Smith"; // Ошибка! (Инкапсуляция)
	s1.sayName();// скажите свое имя
	s1.setMark(6);// добавили оценку 6
	s1.setMark(12);
	std::cout << s1.getMark(0) << std::endl;
	std::cout << s1.getMark(1) << std::endl;

	std::cout << "Возраст: " << s1.getAge() << std::endl;

	return 0;
}