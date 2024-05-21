#include "arena.hpp" //включаем файл

//стрелка - это доступ к методам классов
Arena::Arena() //описание класса объявленного ранее в другом месте
{
    Point2D prey_pos{ rand() % w, rand() % h }; //где жертва
    Point2D predator_pos{ rand() % w, rand() % h }; //где хищник
    while (prey_pos.isTouching(predator_pos)) { //если касается
        predator_pos = Point2D(rand() % w, rand() % h);
    }
    prey = std::make_unique<Prey>(prey_pos);
    predator = std::make_unique<Predator>(predator_pos);
}

bool Arena::isInBounds(const Point2D& point) const //проверка находится ли все внутри арены
{
    return point.X() >= 0 && point.X() < w && point.Y() >= 0 && point.Y() < h;
}

void Arena::play()
{
    prey_is_npc = askForSide(); 
    display();
    while (!prey->getPos().isTouching(predator->getPos())) {
        if (prey_is_npc) {
            const auto [dir_idx, len] = askForPredatorMove();
            predator->move(predator->getAvailableDirsMember()[dir_idx], len);
            prey->moveAsNpc(*this);
        }
        else {
            const int ans = askForPreyMove();
            prey->move(prey->getAvailableDirsMember()[ans]);
            predator->moveAsNpc(*this);
        }
        display();
    }
    std::cout << "game over. prey captured!\n";
    std::cout << prey->getPos().X() << " " << prey->getPos().Y() << "\n";
    std::cout << predator->getPos().X() << " " << predator->getPos().Y();
}

bool Arena::askForSide() const
{
    std::cout << "chosse side\n1 - predator, 2 - prey\n";
    int ans = -1;
    std::cin >> ans;
    while (ans < 1 || ans > 2) {
        std::cout << "wrong, try again!\n";
        std::cin >> ans;
    }
    return ans == 1;
}

int Arena::askForPreyMove() const
{
    std::cout << "Where we go?\n0 - up, 1 - right, 2 - doun, 3 - left, 4 - up left, 5 - up right, 6 - doun right, 7 - doun left\n";
    int ans = -1;
    std::cin >> ans;
    while (ans < 0 || ans > 7 || !isInBounds(prey->getPos() + prey->getAvailableDirsMember()[ans])) {
        std::cout << "wrong number or wall \nTry again\n";
        std::cin >> ans;
    }
    return ans;
}

std::pair<int, int> Arena::askForPredatorMove() const
{
    std::cout << "Where we go?\n0 - up, 1 - right, 2 - doun, 3 - left\n";
    int ans_dir = -1;
    std::cin >> ans_dir;
    while (ans_dir < 0 || ans_dir > 3 || !isInBounds(predator->getPos() + predator->getAvailableDirsMember()[ans_dir])) {
        std::cout << "wrong number or wall \nTry again\n";
        std::cin >> ans_dir;
    }

    std::cout << "how much steps(from 1 to 3)?\n";
    int ans_len = -1;
    std::cin >> ans_len;
    Point2D predator_tmp_pos = predator->getPos();
    predator_tmp_pos.move(predator->getAvailableDirsMember()[ans_dir], std::min(std::max(ans_len, 0), 3));
    while (ans_len < 1 || ans_len > 3 || !isInBounds(predator_tmp_pos)) {
        std::cout << "wrong number or wall\nTry again\n";
        std::cin >> ans_len;
        predator_tmp_pos = predator->getPos();
        predator_tmp_pos.move(predator->getAvailableDirsMember()[ans_dir], std::min(std::max(ans_len, 0), 3));
    }

    return { ans_dir, ans_len };
}

void Arena::display() const {
    // Очисти и поставь курсор на первоначальную позицию
    system("cls");
    std::cout << " " << std::string(w * 2 + 3, '~') << std::endl;
    for (int y = h - 1; y >= 0; --y) {
        std::cout << std::setw(2) << y + 1 << "|";
        for (int x = 0; x < w; ++x) {
            if (prey->getPos() == Point2D(x, y)) {
                std::cout << "()";
            }
            else if (predator->getPos() == Point2D(x, y)) {
                std::cout << "**";
            }
            else {
                std::cout << "  ";
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << " " << std::string(w * 2 + 3, '~') << std::endl;

    std::cout << "  ";
    for (int x = 1; x <= w; ++x) {
        std::cout << std::setw(2) << x;
    }
    std::cout << std::endl;
}