// enumeration - ������������
enum Derections { LEFT = 75, RIGHT = 77, DOWN = 80, UP = 72 };
enum colors { BLACK = 0, GRAY = 8, YELLOW = 14, RED = 12, PINK = 13, GREEN = 2, PURPLE = 5 };
enum elems { HALL = 0, WALL = 1, COIN = 2, ENEMY = 3, MEDICINE_KIT = 4 };

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //���������� ����� ���� ������� (����������)

void SetCursor(int x, int y, int color, string text)
{
    COORD position;
    position.X = x; // ��������� ���������
    position.Y = y;
    SetConsoleCursorPosition(h, position); // ��������� ������� � ����������
	SetConsoleTextAttribute(h, color); // ��������� �����
	cout << text; // ����� ������ ������
}

void SetCursorChar(int x, int y, int color, char text)
{
    COORD position;
    position.X = x; // ��������� ���������
    position.Y = y;
    SetConsoleCursorPosition(h, position); // ��������� ������� � ����������
	SetConsoleTextAttribute(h, color); // ��������� �����
	cout << text; // ����� ������ ������
}

void HideCursor(bool vision, int size) {
	// �������� �������� ������ � �������
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 100;
	SetConsoleCursorInfo(h, &info);
}

void PEndProgram() {
	system("cls");
	SetCursorChar(1, 0, GRAY, (char)201);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 0, GRAY, (char)205);
	}
	SetCursorChar(118, 0, GRAY, (char)187);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(118, i, GRAY, (char)186);
	}
	SetCursorChar(118, 29, GRAY, (char)188);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 29, GRAY, (char)205);
	}
	SetCursorChar(1, 29, GRAY, (char)200);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(1, i, GRAY, (char)186);
	}
	SetCursor(55, 14, RED, "The end...");
	Sleep(INFINITE); // ����� �� ���� ������� ���� ������������ �� ������� ���������
}

void PStartProgram() {
	system("cls");
	SetCursorChar(1, 0, GRAY, (char)201);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 0, GRAY, (char)205);
	}
	SetCursorChar(118, 0, GRAY, (char)187);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(118, i, GRAY, (char)186);
	}
	SetCursorChar(118, 29, GRAY, (char)188);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 29, GRAY, (char)205);
	}
	SetCursorChar(1, 29, GRAY, (char)200);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(1, i, GRAY, (char)186);
	}
	SetCursor(55, 14, GREEN, "You win!!!");
	Sleep(INFINITE); // ����� �� ���� ������� ���� ������������ �� ������� ���������
}

void EndProgram(bool fail) {
	system("cls"); // ������� ������
	if (fail == false) {

		PStartProgram(); // main() - ���������� ����������
	}
	else {
		PEndProgram();
	}
	Sleep(INFINITE); // ����� �� ���� ������� ���� ������������ �� ������� ���������
}

void dyn_walls(int x, int y, int width, int height, int** arr, int elem) {
	if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
		arr[y][x] = elem;
	}
}

void walls(int x, int y, int width, int height, int arr[][60], int elem) {
	if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
		arr[y][x] = elem;
	}
}

void dyn_entry_exit(int x, int y, int width, int height, int** arr, int elem) {
	if (x == 0 && y == 2 || x == 1 && y == 2 || x == 2 && y == 2 || x == width - 1 && y == height - 3 || x == width - 2 && y == height - 3 || x == width - 3 && y == height - 3) {
		arr[y][x] = elem;
	}
}

void entry_exit(int x, int y, int width, int height, int arr[][60], int elem) {
	if (x == 0 && y == 2 || x == 1 && y == 2 || x == 2 && y == 2 || x == width - 1 && y == height - 3 || x == width - 2 && y == height - 3 || x == width - 3 && y == height - 3) {
		arr[y][x] = elem;
	}
}

void dyn_check(int x, int y, int** arr, int item, int elem, int probability) {
	if (arr[y][x] == item) {
		int r;
		r = rand() % probability;
		if (r != 0)
		{
			arr[y][x] = elem;
		}
	}
}

void check(int x, int y, int arr[][60], int item, int elem, int probability) {
	if (arr[y][x] == item) {
		int r;
		r = rand() % probability;
		if (r != 0)
		{
			arr[y][x] = elem;
		}
	}
}

void main_menu(bool& dyn, bool& stat) {
	SetCursor(52, 12, 2, "Classic size");
	SetCursor(52, 14, 13, "Custom size");
	SetCursor(49, 12, 8, "->");
	SetCursor(65, 12, 8, "<-");
	int pos = 0;
	SetCursorChar(1, 0, GRAY, (char)201);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 0, GRAY, (char)205);
	}
	SetCursorChar(118, 0, GRAY, (char)187);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(118, i, GRAY, (char)186);
	}
	SetCursorChar(118, 29, GRAY, (char)188);
	for (int i = 2; i < 118; i++) {
		SetCursorChar(i, 29, GRAY, (char)205);
	}
	SetCursorChar(1, 29, GRAY, (char)200);
	for (int i = 1; i < 29; i++) {
		SetCursorChar(1, i, GRAY, (char)186);
	}
	while (true) {
		int change = _getch();
		if (change == 224) {
			change = _getch();
		}
		if (change == 80 && pos == 0) {
			SetCursor(49, 12, 8, "  ");
			SetCursor(65, 12, 8, "  ");
			SetCursor(49, 14, 8, "->");
			SetCursor(64, 14, 8, "<-");
			pos = 1;
		}
		else if (change == 72 && pos == 1) {
			SetCursor(49, 14, 8, "  ");
			SetCursor(64, 14, 8, "  ");
			SetCursor(49, 12, 8, "->");
			SetCursor(65, 12, 8, "<-");
			pos = 0;
		}
		else if (change == 13) {
			if (pos) {
				dyn = true;
			}
			else {
				stat = true;
			}
			system("cls");
			break;
		}
	}
}

#pragma comment(lib, "winmm.lib")
DWORD WINAPI HitSound(void* param)
{
	PlaySoundA("C:\\Users\\User\\Desktop\\Code\\cw\\sounds\\minecraft_hit_sound.wav", NULL, SND_NODEFAULT | SND_LOOP); // � "" ���� � ������
	return 0;
}

DWORD WINAPI DeathSound(void* param)
{
	PlaySoundA("C:\\Users\\User\\Desktop\\Code\\cw\\sounds\\minecraft_death.wav", NULL, SND_NODEFAULT | SND_LOOP); // � "" ���� � ������
	return 0;
}

DWORD WINAPI PickCoinSound(void* param)
{
	PlaySoundA("C:\\Users\\User\\Desktop\\Code\\cw\\sounds\\minecraft_pick_u.wav", NULL, SND_NODEFAULT | SND_LOOP); // � "" ���� � ������
	return 0;
}

DWORD WINAPI UseKitSound(void* param)
{
	PlaySoundA("C:\\Users\\User\\Desktop\\Code\\cw\\sounds\\medshot4.wav", NULL, SND_NODEFAULT | SND_LOOP); // � "" ���� � ������
	return 0;
}

void StaticMaze() {
	system("title Maze"); // ������ �������� ����� � �������
	HideCursor(false, 100); // �������� �������� ������ � �������
	srand(time(0));

	const int width = 60, height = 20;
	int maze[height][width] = {};

	// �������� - 0     ����� - 1     ������� - 2     ����� - 3     ������� - 4

	///////////////////////////////////////////////////////////////////////
	// ��������� ���������

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			maze[y][x] = rand() % 5;

			walls(x, y, width, height, maze, WALL); // ��������� ����

			entry_exit(x, y, width, height, maze, HALL); // ����������� ����� ����� � ������

			check(x, y, maze, ENEMY, HALL, 10); // ���������� ����������� ��������� ����� (10%)

			check(x, y, maze, MEDICINE_KIT, HALL, 20); // ���������� ����������� ��������� ������� (5%)

			if (maze[y][x] == HALL) {
				SetCursor(x, y, BLACK, " ");
			}
			else if (maze[y][x] == WALL) {
				SetCursorChar(x, y, GRAY, (char)177);
			}
			else if (maze[y][x] == COIN) {
				SetCursor(x, y, YELLOW, "*");
			}
			else if (maze[y][x] == ENEMY) {
				SetCursorChar(x, y, RED, (char)1);
			}
			else if (maze[y][x] == MEDICINE_KIT) {
				SetCursor(x, y, GREEN, "+");
			}
			else {
				cout << maze[y][x];
			}
		}
		cout << endl;
	}

	///////////////////////////////////////////////////////////////////////
	// ���������� ����������

	// ��������� ������� � ����� ���������� �������
	COORD position;
	position.X = 0;
	position.Y = 2;
	SetCursorChar(0, 2, PINK, (char)1);

	int coins = 0; // ���������� ���������� �����
	int health = 100; // ��������
	bool lose = false; // ��������� ���������
	bool write = false; // ���������� �������� ���� (����� �� ������� ������� ��� ���)

	while (true) {
		if (_kbhit()) {
			///////////////////////////////////////////////////////////////////////
			// ������� �����������

			COORD reset_info;
			reset_info.X = width + 1;
			reset_info.Y = 7;
			SetCursor(reset_info.X, reset_info.Y, YELLOW, "RESET GAME - \"R\"");

			///////////////////////////////////////////////////////////////////////
			// ������� ������ 

			COORD exit_info;
			exit_info.X = width + 1;
			exit_info.Y = 5;
			SetCursor(exit_info.X, exit_info.Y, YELLOW, "STOP GAME - \"P\"");

			///////////////////////////////////////////////////////////////////////
			// ���������� ��������

			COORD health_info;
			health_info.X = width + 1;
			health_info.Y = 3;
			SetCursor(health_info.X, health_info.Y, YELLOW, "HEALTH - ");
			cout << health << "%";

			///////////////////////////////////////////////////////////////////////
			// ������������

			int code = _getch(); // get character - ��������� ���� ������� �������
			if (code == 224) // ���� ���� ������ ���������
			{
				code = _getch();
			}
			else if (code == 112) // ���� ������������ ������� ��������� ���������
			{
				PEndProgram();
			}
			else if (code == 114) // ���� ������������ ������� ������������� ���������
			{
				system("cls");
				StaticMaze();
			}

			SetCursor(position.X, position.Y, BLACK, " ");

			COORD kit_pos; // �������� ������ ��������� �������
			kit_pos.X = 0;
			kit_pos.Y = 0;
			if (write) // 2 ���� �������� �������� �������
			{
				kit_pos.X = position.X; // ����������� ��������� ������� (�� ����)
				kit_pos.Y = position.Y;
				write = false; // ��������� ���������� ����� ������ ���������
			}

			if (code == RIGHT && maze[position.Y][position.X + 1] != WALL) {
				position.X++; // �������� ������
			}
			else if (code == LEFT && maze[position.Y][position.X - 1] != WALL) {
				position.X--; // �������� �����
			}
			else if (code == UP && maze[position.Y - 1][position.X] != WALL) {
				position.Y--; // �������� �����
			}
			else if (code == DOWN && maze[position.Y + 1][position.X] != WALL) {
				position.Y++; // �������� ����
			}

			if (kit_pos.X > 0) // ���� �������� ���������� �������, ���������� �� �� ����� (3 ���� �������� �������� �������)
			{
				SetCursor(kit_pos.X, kit_pos.Y, GREEN, "+");
			}

			if (maze[position.Y][position.X] == ENEMY) // �������� ������� �����
			{
				health -= 25;
				if (health != 0) {
					CreateThread(0, 0, HitSound, 0, 0, 0);
				}
				maze[position.Y][position.X] = HALL;
				health_info.X += 12;
				SetCursor(health_info.X, health_info.Y, YELLOW, " ");
				if (health == 0) {
					CreateThread(0, 0, DeathSound, 0, 0, 0);
					lose = true;
					MessageBoxA(0, "����������� ��������!", "��������� :(", MB_OK);
					PEndProgram();
				}
			}

			if (maze[position.Y][position.X] == MEDICINE_KIT && health != 100) // ������������� �������
			{
				health += 25;
				CreateThread(0, 0, UseKitSound, 0, 0, 0);
				maze[position.Y][position.X] = HALL;
			}
			else if (maze[position.Y][position.X] == MEDICINE_KIT && health == 100) // 1 ���� �������� �������� �������
			{
				write = true;
			}

			SetCursorChar(position.X, position.Y, PINK, (char)1);

			///////////////////////////////////////////////////////////////////////
			// �������� �� ����� �� ���������

			if (position.X == width - 1 && position.Y == height - 3) {
				MessageBoxA(0, "������ ����� �� ���������!", "������!", MB_OK);
				break;
			}

			///////////////////////////////////////////////////////////////////////
			// �������� �� ������ �������

			if (maze[position.Y][position.X] == COIN) {
				coins++;
				CreateThread(0, 0, PickCoinSound, 0, 0, 0);
				maze[position.Y][position.X] = HALL;
				SetCursor(width + 1, 1, YELLOW, "COINS - ");
				SetCursor(width + 9, 1, YELLOW, to_string(coins));
			}
		}
		else {
			Sleep(20);
			COORD enemy_pos[100];
			int enemy_count = 0;

			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{

					if (maze[y][x] == ENEMY)
					{
						enemy_pos[enemy_count].X = x;
						enemy_pos[enemy_count].Y = y;
						enemy_count++;
					}
				}
			}
			//������������ ������
			for (int i = 0; i < enemy_count; i++)
			{
				int r = rand() % 100;
				if (r == LEFT &&
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] != WALL &&
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X - 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] = ENEMY;
				}
				else if (r == RIGHT &&
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] != WALL &&
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X + 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] = ENEMY;
				}
				else if (r == UP &&
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] != WALL &&
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y - 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] = ENEMY;
				}
				else if (r == DOWN &&
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] != WALL &&
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;

					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y + 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] = ENEMY;
				}
			}
		}
	}

	for (int y = 0; y < height; y++) {
		delete[] maze[y];
	}
	delete[] maze;
	
	EndProgram(lose);
}

void DynamicMaze() {
	system("title Maze"); // ������ �������� ����� � �������
	HideCursor(false, 100); // �������� �������� ������ � �������
	srand(time(0));

	unsigned int width;
	unsigned int height;
	SetCursor(2, 1, YELLOW, "Please, enter amount of columns: ");
	cin >> width;
	SetCursor(2, 3, YELLOW, "Please, enter amount of rows: ");
	cin >> height;

	int** maze = new int* [width];
	for (int y = 0; y < width; y++) {
		maze[y] = new int[height];
	}

	system("cls");

	// �������� - 0     ����� - 1     ������� - 2     ����� - 3     ������� - 4

	///////////////////////////////////////////////////////////////////////
	// ��������� ���������

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			maze[y][x] = rand() % 5;

			dyn_walls(x, y, width, height, maze, WALL); // ��������� ����

			dyn_entry_exit(x, y, width, height, maze, HALL); // ����������� ����� ����� � ������

			dyn_check(x, y, maze, ENEMY, HALL, 10); // ���������� ����������� ��������� ����� (10%)

			dyn_check(x, y, maze, MEDICINE_KIT, HALL, 20); // ���������� ����������� ��������� ������� (5%)

			if (maze[y][x] == HALL) {
				SetCursor(x, y, BLACK, " ");
			}
			else if (maze[y][x] == WALL) {
				SetCursorChar(x, y, GRAY, (char)177);
			}
			else if (maze[y][x] == COIN) {
				SetCursor(x, y, YELLOW, "*");
			}
			else if (maze[y][x] == ENEMY) {
				SetCursorChar(x, y, RED, (char)1);
			}
			else if (maze[y][x] == MEDICINE_KIT) {
				SetCursor(x, y, GREEN, "+");
			}
			else {
				cout << maze[y][x];
			}
		}
		cout << endl;
	}

	///////////////////////////////////////////////////////////////////////
	// ���������� ����������

	// ��������� ������� � ����� ���������� �������
	COORD position;
	position.X = 0;
	position.Y = 2;
	SetCursorChar(0, 2, PINK, (char)1);

	int coins = 0; // ���������� ���������� �����
	int health = 100; // ��������
	bool lose = false; // ��������� ���������
	bool write = false; // ���������� �������� ���� (����� �� ������� ������� ��� ���)

	while (true) {
		if (_kbhit()) {
			///////////////////////////////////////////////////////////////////////
			// ������� �����������

			COORD reset_info;
			reset_info.X = width + 1;
			reset_info.Y = 7;
			SetCursor(reset_info.X, reset_info.Y, YELLOW, "RESET GAME - \"R\"");

			///////////////////////////////////////////////////////////////////////
			// ������� ������ 

			COORD exit_info;
			exit_info.X = width + 1;
			exit_info.Y = 5;
			SetCursor(exit_info.X, exit_info.Y, YELLOW, "STOP GAME - \"P\"");

			///////////////////////////////////////////////////////////////////////
			// ���������� ��������

			COORD health_info;
			health_info.X = width + 1;
			health_info.Y = 3;
			SetCursor(health_info.X, health_info.Y, YELLOW, "HEALTH - ");
			cout << health << "%";

			///////////////////////////////////////////////////////////////////////
			// ������������

			int code = _getch(); // get character - ��������� ���� ������� �������
			if (code == 224) // ���� ���� ������ ���������
			{
				code = _getch();
			}
			else if (code == 112) // ���� ������������ ������� ��������� ���������
			{
				PEndProgram();
			}
			else if (code == 114) // ���� ������������ ������� ������������� ���������
			{
				system("cls");
				DynamicMaze();
			}

			SetCursor(position.X, position.Y, BLACK, " ");

			COORD kit_pos; // �������� ������ ��������� �������
			kit_pos.X = 0;
			kit_pos.Y = 0;
			if (write) // 2 ���� �������� �������� �������
			{
				kit_pos.X = position.X; // ����������� ��������� ������� (�� ����)
				kit_pos.Y = position.Y;
				write = false; // ��������� ���������� ����� ������ ���������
			}

			if (code == RIGHT && maze[position.Y][position.X + 1] != WALL) {
				position.X++; // �������� ������
			}
			else if (code == LEFT && maze[position.Y][position.X - 1] != WALL) {
				position.X--; // �������� �����
			}
			else if (code == UP && maze[position.Y - 1][position.X] != WALL) {
				position.Y--; // �������� �����
			}
			else if (code == DOWN && maze[position.Y + 1][position.X] != WALL) {
				position.Y++; // �������� ����
			}

			if (kit_pos.X > 0) // ���� �������� ���������� �������, ���������� �� �� ����� (3 ���� �������� �������� �������)
			{
				SetCursor(kit_pos.X, kit_pos.Y, GREEN, "+");
			}

			if (maze[position.Y][position.X] == ENEMY) // �������� ������� �����
			{
				health -= 25;
				if (health != 0) {
					CreateThread(0, 0, HitSound, 0, 0, 0);
				}
				maze[position.Y][position.X] = HALL;
				health_info.X += 12;
				SetCursor(health_info.X, health_info.Y, YELLOW, " ");
				if (health == 0) {
					CreateThread(0, 0, DeathSound, 0, 0, 0);
					lose = true;
					MessageBoxA(0, "����������� ��������!", "��������� :(", MB_OK);
					PEndProgram();
				}
			}

			if (maze[position.Y][position.X] == MEDICINE_KIT && health != 100) // ������������� �������
			{
				health += 25;
				CreateThread(0, 0, UseKitSound, 0, 0, 0);
				maze[position.Y][position.X] = HALL;
			}
			else if (maze[position.Y][position.X] == MEDICINE_KIT && health == 100) // 1 ���� �������� �������� �������
			{
				write = true;
			}

			SetCursorChar(position.X, position.Y, PINK, (char)1);

			///////////////////////////////////////////////////////////////////////
			// �������� �� ����� �� ���������

			if (position.X == width - 1 && position.Y == height - 3) {
				MessageBoxA(0, "������ ����� �� ���������!", "������!", MB_OK);
				break;
			}

			///////////////////////////////////////////////////////////////////////
			// �������� �� ������ �������

			if (maze[position.Y][position.X] == COIN) {
				coins++;
				CreateThread(0, 0, PickCoinSound, 0, 0, 0);
				maze[position.Y][position.X] = HALL;
				SetCursor(width + 1, 1, YELLOW, "COINS - ");
				SetCursor(width + 9, 1, YELLOW, to_string(coins));
			}
		}
		else {
			Sleep(20);
			COORD enemy_pos[100];
			int enemy_count = 0;

			for (int y = 0; y < height; y++)
			{
				for (int x = 0; x < width; x++)
				{

					if (maze[y][x] == ENEMY)
					{
						enemy_pos[enemy_count].X = x;
						enemy_pos[enemy_count].Y = y;
						enemy_count++;
					}
				}
			}
			//������������ ������
			for (int i = 0; i < enemy_count; i++)
			{
				int r = rand() % 100;
				if (r == LEFT &&
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] != WALL &&
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X - 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y][enemy_pos[i].X - 1] = ENEMY;
				}
				else if (r == RIGHT &&
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] != WALL &&
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X + 1;
					temp.Y = enemy_pos[i].Y;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y][enemy_pos[i].X + 1] = ENEMY;
				}
				else if (r == UP &&
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] != WALL &&
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;


					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y - 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y - 1][enemy_pos[i].X] = ENEMY;
				}
				else if (r == DOWN &&
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] != WALL &&
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] != ENEMY)
				{

					COORD temp = enemy_pos[i];
					SetConsoleCursorPosition(h, temp);
					cout << " ";
					maze[enemy_pos[i].Y][enemy_pos[i].X] = HALL;

					temp.X = enemy_pos[i].X;
					temp.Y = enemy_pos[i].Y + 1;
					SetConsoleCursorPosition(h, temp);
					SetConsoleTextAttribute(h, RED);
					cout << (char)1;
					maze[enemy_pos[i].Y + 1][enemy_pos[i].X] = ENEMY;
				}
			}
		}
	}

	for (int y = 0; y < height; y++) {
		delete[] maze[y];
	}
	delete[] maze;

	EndProgram(lose);
}