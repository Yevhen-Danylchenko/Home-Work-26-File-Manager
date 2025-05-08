#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


//======================== Робота з файлами =============================
//========================= Створення файлу =============================

std::string line;

void createFile() {
    std::ofstream my_file_for_write("File.txt");
    if (my_file_for_write.is_open()) {
        while (true) {
            std::cout << "Введiть текст (використовуйте stop для виходу з програми): \t";
            std::cin >> line;
            if (line != "stop") {
                my_file_for_write << line << std::endl;                
            }
            else {
                break;
            }
        }
    }
        else
        {
            std::cout << "Помилка. Файл не знайдений.";
        }
    my_file_for_write.close();
}

//========================= Переіменування файлу =============================

void renameFile() {
    std::string lastName, newName;
    std::cout << "Введiть назву файла: \t";
    std::cin >> lastName;
    std::cout << "Введiть нову назву файла: \t";
    std::cin >> newName;

    if (rename(lastName.c_str(), newName.c_str()) == 0) {
        std::cout << "Файл переiменований " << newName << std::endl;
    }
    else {
        std::cout << "Помилка у переiменованнi файлу. \n";
    }
}

//========================= Видалення файлу =============================

void removeFile() {
    std::string fileName;

    std::cout << "Введiть назву видаляємого файлу: \t";
    std::cin >> fileName;

    if (remove(fileName.c_str()) == 0) {
        std::cout << "Файл видалений. \n";
    }
    else {
        std::cout << "Помилка. Неможливо видалити файл. \n";
    }
}

//========================= Переміщення файлу =============================

void moveFile() {
    std::string fileName, newPath;

    std::cout << "Введiть назву перемiщуємого файлу: \t";
    std::cin >> fileName;
    std::cout << "Введiть куди перемiстити файл директорiю: \t";
    std::cin >> newPath;

    if (rename(fileName.c_str(), newPath.c_str()) == 0) {
        std::cout << "Файл перемiщений у " << newPath << std::endl;
    }
    else {
        std::cout << "Помилка. Файл не знайдено. \n";
    }
}

//========================= Читання файлу =============================

void readFile() {
    std::string fileName;
    std::cout << "Введiть назву файлу для прочитання: \t";
    std::cin >> fileName;

    std::ifstream my_file_for_read(fileName.c_str());
    
    if (my_file_for_read.is_open()) {
        while (std::getline(my_file_for_read, line)) {
            std::cout << line << std::endl;
        }
        my_file_for_read.close();
    }
    else {
        std::cout << "Помилка. Файл не знайдено. \n";
    }
}

//========================= Запис у файл =============================

void writeFile() {
	std::string fileName;
	std::cout << "Введiть назву файлу для запису: \t";
	std::cin >> fileName;

	std::ofstream my_file_for_write(fileName.c_str(), std::ios::app);

	if (my_file_for_write.is_open()) {
		while (true) {
			std::cout << "Ведiть текст(stop для зупинки запису): \t";
			std::cin >> line;
			if (line != "stop") {
				my_file_for_write << line << std::endl;
			}
			else {
				break;
			}
		}
		my_file_for_write.close();
	}
	else {
		std::cout << "Помилка. Файл не знайдено. \n";
	}
}

//========================= Обчислювання розміру файлу =============================

void fileSize() {
	std::string fileName;
	std::cout << "Введiть назву файла для обчислювання розмiру: \t";
	std::cin >> fileName;

	std::ifstream my_file_for_size(fileName.c_str(), std::ios::binary);

	if (my_file_for_size.is_open()) {
		my_file_for_size.seekg(0, std::ios::end);
		std::streamsize size = my_file_for_size.tellg();
		std::cout << "Розмiр файла: " << size << " байт." << std::endl;
		my_file_for_size.close();
	}
	else {
		std::cout << "Помилка. Файл не знайдено. \n";
	}
}

//========================= Інтерфейс користувача =============================

void menu() {
	int choice;
	do {
		std::cout << "1. Створити файл\n";
		std::cout << "2. Перейменувати файл\n";
		std::cout << "3. Видалити файл\n";
		std::cout << "4. Перемiщувати файл\n";
		std::cout << "5. Читати файл\n";
		std::cout << "6. Записувати файл\n";
		std::cout << "7. Розмiр файлу\n";
		std::cout << "8. Вихiд з програми\n";
		std::cout << "Введiть ваш вибiр: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			createFile();
			break;
		case 2:
			renameFile();
			break;
		case 3:
			removeFile();
			break;
		case 4:
			moveFile();
			break;
		case 5:
			readFile();
			break;
		case 6:
			writeFile();
			break;
		case 7:
			fileSize();
			break;
		case 8:
			std::cout << "Виход...\n";
			break;
		default:
			std::cout << "Невiрний вибiр. Спробуйте ще раз.\n";
		}
	} while (choice != 8);
}
