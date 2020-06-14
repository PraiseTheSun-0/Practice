#include <iostream>
bool found = false;

void find_path (std::string arr[], int a, int b){
    arr[a][b] = '*';
    if (isalpha(arr[a-1][b])){
        std::cout << arr[a-1][b] << ' ';
        found = true;
    }
    if (isalpha(arr[a+1][b])){
        std::cout << arr[a+1][b] << ' ';
        found = true;
    }
    if (isalpha(arr[a][b+1])){
        std::cout << arr[a][b+1] << ' ';
        found = true;
    }
    if (isalpha(arr[a][b-1])){
        std::cout << arr[a][b-1] << ' ';
        found = true;
    }
    if (arr[a-1][b]==' ')find_path(arr, a-1, b);
    if (arr[a+1][b]==' ')find_path(arr, a+1, b);
    if (arr[a][b-1]==' ')find_path(arr, a, b-1);
    if (arr[a][b+1]==' ')find_path(arr, a, b+1);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::string maze[25] = {
    "####B######################",
    "# #       #   #      #    #",
    "# # # ###### #### ####### #",
    "# # # #       #   #       #",
    "#   # # ########### ##### #",
    "# # # #   #       #     # #",
    "### ### ### ############# #",
    "# #   #     # #           #",
    "# # #   ####### ###########",
    "# # # #       # #         C",
    "# # ##### ### # # ####### #",
    "# # #     ### # #       # #",
    "#   ##### ### # ######### #",
    "######### ### #           #",
    "# ####### ### #############",
    "A #         #   ###   #   #",
    "# ############# ### # # # #",
    "# ###       # # ### # # # #",
    "# ######### # # ### # # # F",
    "#       ### # #     # # # #",
    "# ######### # ##### # # # #",
    "# #######   #       #   # #",
    "# ####### ######### #######",
    "#         #########       #",
    "#######E############D######"
    };
    int column, row;
    std::cin >> column >> row;
    if (column>26 || row>24 || maze[row][column]=='#') {
        std::cout << "Неверные координаты";
        return 0;
    }
    find_path(maze, row, column);
    if(!found)std::cout << "Выхода нет";
    return 0;
}
