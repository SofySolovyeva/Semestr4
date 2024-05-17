#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct Book {
    std::string id;
    std::string author;
    std::string naz;
    int pages;

    friend std::istream& operator>>(std::istream& is, Book& book) {
        is >> book.id >> book.author >> book.naz >> book.pages;
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << book.id << " " << book.author << " " << book.naz << " " << book.pages;
        return os;
    }
};

struct Matrix {
    std::vector<std::vector<int>> data;
};

void addBook(std::vector<Book>& books, const Book& newBook) {
    std::string filename = "Books.txt";
    std::ofstream outBook;
    
    outBook.open(filename, std::ios::app);
    if (!outBook.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << " для записи" << std::endl;
        return;
    }
    books.push_back(newBook);
    outBook << newBook << std::endl;
    outBook.close();
}

void viewBooks() {
    std::string filename = "Books.txt";
    std::vector<Book> books;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Book book;
        while (inFile >> book) {
            books.push_back(book);
        }
        inFile.close();
    } else {
        std::cerr << "Все сломалсь" << filename << std::endl;
        return;
    }

    for (const auto& book : books) {
        std::cout << book.id << " " << book.author << " " << book.naz << " " << book.pages << std::endl;
    }
}

void deleteBook(const std::string& id) {
    std::string filename = "Books.txt";
    std::vector<Book> books;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Book book;
        while (inFile >> book) {
            books.push_back(book);
        }
        inFile.close();
    } else {
        std::cerr << "Все сломалась" << filename << std::endl;
        return;
    }

    books.erase(std::remove_if(books.begin(), books.end(), [&id](const Book& book) { return book.id == id; }), books.end());

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& book : books) {
            outFile << book << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Не удалось открыть файл " << filename << " для записи" << std::endl;
    }
}

void searchBook(const std::string& naz) {
    std::string filename = "Books.txt";
    std::vector<Book> books;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Book book;
        while (inFile >> book) {
            books.push_back(book);
        }
        inFile.close();
    } else {
        std::cerr << "Все сломалась" << filename << std::endl;
        return;
    }

    auto it = std::find_if(books.begin(), books.end(), [&naz](const Book& book) { return book.naz == naz; });
    if (it != books.end()) {
        std::cout << it->id << " " << it->author << " " << it->naz << " " << it->pages << std::endl;
    } else {
        std::cout << "Книги нет" << std::endl;
    }
}

void editBook(const std::string& id, const Book& updatedBook) {
    std::string filename = "Books.txt";
    std::vector<Book> books;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        Book book;
        while (inFile >> book) {
            books.push_back(book);
        }
        inFile.close();
    } else {
        std::cerr << "Все сломалась" << filename << std::endl;
        return;
    }

    auto it = std::find_if(books.begin(), books.end(), [&id](const Book& book) { return book.id == id; });
    if (it != books.end()) {
        *it = updatedBook;
    } else {
        std::cout << "Книга не найдена." << std::endl;
        return;
    }

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& book : books) {
            outFile << book << std::endl;
        }
        outFile.close();
    } else {
        std::cerr << "Не удалось открыть файл " << filename << " для записи" << std::endl;
    }
}


void writeMatrixToFile(const std::string& filename, const Matrix& matrix) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Все сломалось" << filename << std::endl;
        return;
    }

    for (const auto& row : matrix.data) {
        for (int value : row) {
            file << value << ' ';
        }
        file << '\n';
    }

    file.close();
}

Matrix readMatrixFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return Matrix{};
    }

    Matrix matrix;
    int value;
    while (file >> value) {
        std::vector<int> row;
        row.push_back(value);
        while (file.peek() != '\n' && file >> value) {
            row.push_back(value);
        }
        matrix.data.push_back(row);
    }

    file.close();
    return matrix;
}

int countWordOccurrences(const std::string& filename, const std::string& word) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл " << filename << std::endl;
        return -1;
    }

    std::string line;
    int count = 0;
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != std::string::npos) {
            ++count;
            pos += word.length();
        }
    }

    file.close();
    return count;
}

int main() {
    std::vector<Book> books;
    std::string filename = "Books.txt";
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string id;
        std::string author;
        std::string naz;
        int pages;
        while (file >> id >> author >> naz >> pages) {
            books.push_back({id, author, naz, pages});
        }
        file.close();
    }

    int choice;
    std::string input;

    do {
        std::cout << "Выберете действие:\n"
                  << "1. Добавить книгу\n"
                  << "2. Посмотреть все книги\n"
                  << "3. Удалить книгу \n"
                  << "4. Поиск книги \n"
                  << "5. Редактировать книгу\n"
                  << "6. Посчитать сколько слов в файле\n"
                  << "7. Выход\n";
        std::cin >> input;

        std::istringstream iss(input);
    if (!(iss >> choice)) {
        std::cout << "сламалася все, сделай снова" << std::endl;
        return 1; // Завершаем программу с кодом ошибки
    }

    choice = std::stoi(input);

        switch (choice) {
            case 1: {
                Book newBook;
                std::cout << "  Введите id, автора, название и количество страниц: ";
                std::cin >> newBook.id >> newBook.author >> newBook.naz >> newBook.pages;
                addBook(books, newBook);
                break;
            }
            case 2:
                viewBooks();
                break;
            case 3: {
                std::string id;
                std::cout << "Введите id книги, которую хотите удалить ";
                std::cin >> id;
                deleteBook(id);
                break;
            }
            case 4: {
                std::string naz;
                std::cout << "введите название книги, которую ищите ";
                std::cin >> naz;
                searchBook(naz);
                break;
            }
            case 5: {
                std::string id;
                Book updatedBook;
                std::cout << "Ведите id книги, которую хотите редактировать: ";
                std::cin >> id;
                std::cout << "ведите новую дату: ";
                std::cin >> updatedBook.id >> updatedBook.author >> updatedBook.naz >> updatedBook.pages;
                editBook(id, updatedBook);
                break;
            }
            case 6: {
                std::string filename;
                std::string word;
                std::cout << "Ведите название файла и слово: ";
                std::cin >> filename >> word;
                int occurrences = countWordOccurrences(filename, word);
                std::cout << "слово '" << word << " встречается " << occurrences << " количество раз." << std::endl;
                break;
            }
            case 7:
                std::cout << "выйти из программы." << std::endl;
                break;
            default:
                std::cout << "заново" << std::endl;
                break;
        }
    } while (choice != 7);

    return 0;
}