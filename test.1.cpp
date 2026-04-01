#include <iostream>
#include <vector>

#include "board.hpp"

int main(int argc, char *argv[]) {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> b(n, std::vector<int> (n));
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n; ++j) {
			std::cin >> b[i][j];
		}
	}
	std::vector<std::vector<int>> e(3, std::vector<int> (3));
	for(int i=0; i<3; ++i) {
		for(int j=0; j<3; ++j) {
			std::cin >> e[i][j];
		}
	}
	board_t board(b);
	board.print_board();
	board.play_move('D');
	board.print_board();
	board.print_stats();
	board.play_move('U');
	bool correct = board.submit(e);
	if(correct) {
		std::cout << "CORRECT" << std::endl;
		board.print_stats();
	}
	else {
		std::cout << "WRONG" << std::endl;
	}
}
