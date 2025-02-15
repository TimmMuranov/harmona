#include <iostream>
#include <vector>
#include <string>
#include <ncurses.h>

// Функция для вывода списка функций
void display_menu(std::vector<std::string>& options, int highlight);

int main() {
    initscr();                 // Инициализация ncurses
    cbreak();                  // Отключаем буферизацию ввода
    noecho();                  // Отключаем эхо символов
    keypad(stdscr, TRUE);      // Включаем поддержку специальных клавиш

    std::vector<std::string> menu_options = {"Creat note", "Creat key", "Get functions"};
    int highlight = 0;
    int choice = 0;

    while (true) {
        clear();      // Очищаем экран перед каждым выводом меню
        display_menu(menu_options, highlight);

        int c = getch();  // Получение символа от пользователя

        switch(c) {
            case KEY_UP:
                if (highlight == 0)
                    highlight = menu_options.size() - 1;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == menu_options.size() - 1)
                    highlight = 0;
                else
                    ++highlight;
                break;
            case 10:  // Код клавиши Enter
                choice = highlight + 1;
                goto end_while;
                break;
            default:
                break;
        }
    }
end_while:

    // Завершение работы ncurses
    endwin();

    // Выполнение выбранной функции
    std::cout << "Вы выбрали функцию " << choice << ": " << menu_options[choice - 1] << std::endl;

    return 0;
}

// Функция для отображения меню
void display_menu(std::vector<std::string>& options, int selected_option) {
    for (size_t i = 0; i < options.size(); ++i) {
        if (static_cast<int>(i) == selected_option) {  // Подсвечиваем текущую строку
            attron(A_REVERSE);
            mvprintw(i, 0, "%s", options[i].c_str());
            attroff(A_REVERSE);
        } else {
            mvprintw(i, 0, "%s", options[i].c_str());
        }
    }
    refresh();  // Обновляем экран
}
