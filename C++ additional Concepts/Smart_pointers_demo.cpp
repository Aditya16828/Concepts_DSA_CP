#include <bits/stdc++.h>
#define ll long long int

struct Player
{
	int x, y;
	void display()
	{
		std::cout << x << " " << y << "\n";
	}
	~Player()
	{
		std::cout << "Player Destroyed\n";
	}
};

int main()
{
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	{
		// std::unique_ptr<Player> ptr1 = std::make_unique<Player>(); // destructor will be called
		Player *ptr1 = new Player; // no destructor will be called
		ptr1->x = 10;
		ptr1->y = 20;
		ptr1->display();
	}
	std::cout << "******\n";

	std::shared_ptr<Player> ptr2 = std::make_shared<Player>();
	std::shared_ptr<Player> ptr3 = ptr2;
	std::cout << ptr2.use_count() << ", " << ptr3.use_count() << "\n";

	std::weak_ptr<Player> ptw(ptr3);
	std::cout << ptw.use_count() << "\n";

	std::unique_ptr<int> p1 = std::make_unique<int>();
	std::unique_ptr<int[]> p2(new int[9]);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}