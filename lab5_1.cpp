
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Функция для подсчета количества появлений слова в текстовом файле
int countWordOccurrences(const string& word, const string& filename) {
    ifstream file(filename);
    string line;
    int count = 0;

    while (getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(word, pos)) != string::npos) {
            count++;
            pos += word.length();
        }
    }

    file.close();
    return count;
}

// Структура для матрицы
struct Matrix {
    int rows;
    int cols;
};

int main() {
    // Задание слова для поиска и имени файла
    string word = "example";
    string filename = "textfile.txt";

    // Пример использования функции countWordOccurrences
    int occurrences = countWordOccurrences(word, filename);
    cout << "Word '" << word << "' occurs " << occurrences << " times in the file." << endl;

    // Запись нескольких объектов Matrix в текстовый файл
    vector<Matrix> matrices = {{2, 3}, {3, 3}, {4, 2}};
    ofstream textFile("matrices.txt");
    for (const Matrix& m : matrices) {
        textFile << m.rows << " " << m.cols << endl;
    }
    textFile.close();

    // Чтение записанных объектов из текстового файла
    ifstream textFileRead("matrices.txt");
    vector<Matrix> matricesRead;
    Matrix temp;
    while (textFileRead >> temp.rows >> temp.cols) {
        matricesRead.push_back(temp);
    }
    textFileRead.close();

    // Повторение действий с использованием бинарного файла
    ofstream binFile("matrices.bin", ios::binary);
    for (const Matrix& m : matrices) {
        binFile.write((char*)&m, sizeof(Matrix));
    }
    binFile.close();

    ifstream binFileRead("matrices.bin", ios::binary);
    vector<Matrix> matricesBinRead;
    while (binFileRead.read((char*)&temp, sizeof(Matrix))) {
        matricesBinRead.push_back(temp);
    }
    binFileRead.close();

    // Программа манипуляции с каталогом книг
    struct Book {
        string id;
        string author;
        string title;
        int pages;
    };

    vector<Book> catalog;

    // Функция для добавления новой записи
    auto addBookEntry = [&catalog](const Book& book) {
        catalog.push_back(book);
    };

    // Функция для просмотра всех записей
    auto viewAllEntries = [&catalog]() {
        for (const Book& book : catalog) {
            cout << "ID: " << book.id << ", Author: " << book.author << ", Title: " << book.title << ", Pages: " << book.pages << endl;
        }
    };

    // Функция для удаления записи
    auto deleteBookEntry = [&catalog](const string& id) {
        for (auto it = catalog.begin(); it != catalog.end(); ++it) {
            if (it->id == id) {
                catalog.erase(it);
                break;
            }
        }
    };

    // Функция для поиска записи
    auto findBookEntry = [&catalog](const string& id) -> Book* {
        for (Book& book : catalog) {
            if (book.id == id) {
                return &book;
            }
        }
        return nullptr;
    };

    // Функция для редактирования записи
    auto editBookEntry = [&catalog](const string& id, const Book& newBook) {
        for (Book& book : catalog) {
            if (book.id == id) {
                book = newBook;
                break;
            }
        }
    };

    // Пример использования функций манипуляции с каталогом книг
    Book book1 = {"0001", "A.S.Pushkin", "Dubrovsky", 142};
    Book book2 = {"0002", "Y.Gibson", "Neuromancer", 347};

    addBookEntry(book1);
    addBookEntry(book2);

    cout << "All Entries:" << endl;
    viewAllEntries();

    cout << "Deleting entry with ID '0001'..." << endl;
    deleteBookEntry("0001");

    cout << "All Entries after deletion:" << endl;

viewAllEntries();

    cout << "Finding entry with ID '0002'..." << endl;
    Book* foundBook = findBookEntry("0002");
    if (foundBook != nullptr) {
        cout << "Found: ID: " << foundBook->id << ", Author: " << foundBook->author 
             << ", Title: " << foundBook->title << ", Pages: " << foundBook->pages << endl;
    } else {
        cout << "Entry not found." << endl;
    }

    cout << "Editing entry with ID '0002'..." << endl;
    Book newBook2 = {"0002", "William Gibson", "Neuromancer", 350};
    
    editBookEntry("0002", newBook2);

    cout << "All Entries after editing:" << endl;
    viewAllEntries();

    return 0;
}
