#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


//======================== ������ � ������� =============================
//========================= ��������� ����� =============================

std::string line;

void createFile() {
    std::ofstream my_file_for_write("File.txt");
    if (my_file_for_write.is_open()) {
        while (true) {
            std::cout << "����i�� ����� (�������������� stop ��� ������ � ��������): \t";
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
            std::cout << "�������. ���� �� ���������.";
        }
    my_file_for_write.close();
}

//========================= ������������� ����� =============================

void renameFile() {
    std::string lastName, newName;
    std::cout << "����i�� ����� �����: \t";
    std::cin >> lastName;
    std::cout << "����i�� ���� ����� �����: \t";
    std::cin >> newName;

    if (rename(lastName.c_str(), newName.c_str()) == 0) {
        std::cout << "���� ����i��������� " << newName << std::endl;
    }
    else {
        std::cout << "������� � ����i��������i �����. \n";
    }
}

//========================= ��������� ����� =============================

void removeFile() {
    std::string fileName;

    std::cout << "����i�� ����� ����������� �����: \t";
    std::cin >> fileName;

    if (remove(fileName.c_str()) == 0) {
        std::cout << "���� ���������. \n";
    }
    else {
        std::cout << "�������. ��������� �������� ����. \n";
    }
}

//========================= ���������� ����� =============================

void moveFile() {
    std::string fileName, newPath;

    std::cout << "����i�� ����� �����i������ �����: \t";
    std::cin >> fileName;
    std::cout << "����i�� ���� �����i����� ���� ��������i�: \t";
    std::cin >> newPath;

    if (rename(fileName.c_str(), newPath.c_str()) == 0) {
        std::cout << "���� �����i����� � " << newPath << std::endl;
    }
    else {
        std::cout << "�������. ���� �� ��������. \n";
    }
}

//========================= ������� ����� =============================

void readFile() {
    std::string fileName;
    std::cout << "����i�� ����� ����� ��� ����������: \t";
    std::cin >> fileName;

    std::ifstream my_file_for_read(fileName.c_str());
    
    if (my_file_for_read.is_open()) {
        while (std::getline(my_file_for_read, line)) {
            std::cout << line << std::endl;
        }
        my_file_for_read.close();
    }
    else {
        std::cout << "�������. ���� �� ��������. \n";
    }
}

//========================= ����� � ���� =============================

void writeFile() {
	std::string fileName;
	std::cout << "����i�� ����� ����� ��� ������: \t";
	std::cin >> fileName;

	std::ofstream my_file_for_write(fileName.c_str(), std::ios::app);

	if (my_file_for_write.is_open()) {
		while (true) {
			std::cout << "���i�� �����(stop ��� ������� ������): \t";
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
		std::cout << "�������. ���� �� ��������. \n";
	}
}

//========================= ������������ ������ ����� =============================

void fileSize() {
	std::string fileName;
	std::cout << "����i�� ����� ����� ��� ������������ ����i��: \t";
	std::cin >> fileName;

	std::ifstream my_file_for_size(fileName.c_str(), std::ios::binary);

	if (my_file_for_size.is_open()) {
		my_file_for_size.seekg(0, std::ios::end);
		std::streamsize size = my_file_for_size.tellg();
		std::cout << "����i� �����: " << size << " ����." << std::endl;
		my_file_for_size.close();
	}
	else {
		std::cout << "�������. ���� �� ��������. \n";
	}
}

//========================= ��������� ����������� =============================

void menu() {
	int choice;
	do {
		std::cout << "1. �������� ����\n";
		std::cout << "2. ������������� ����\n";
		std::cout << "3. �������� ����\n";
		std::cout << "4. �����i������ ����\n";
		std::cout << "5. ������ ����\n";
		std::cout << "6. ���������� ����\n";
		std::cout << "7. ����i� �����\n";
		std::cout << "8. ���i� � ��������\n";
		std::cout << "����i�� ��� ���i�: ";
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
			std::cout << "�����...\n";
			break;
		default:
			std::cout << "���i���� ���i�. ��������� �� ���.\n";
		}
	} while (choice != 8);
}
