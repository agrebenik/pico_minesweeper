#include "picosystem.hpp"

using namespace picosystem;

// these includes are important
#include <cstdlib>
#include <ctime>
#include <string>

using std::string;
using std::rand;

// ============================================
//                 CONSTANTS
// ============================================

const unsigned int MINES = 10;
const unsigned int SIZE = 9;

// palette
color_t col_a = rgb(255, 255, 255);
color_t col_b = rgb(189, 189, 189);
color_t col_c = rgb(123, 123, 123);
color_t col_d = rgb(0, 0, 0);
color_t col_e = rgb(0, 0, 255);
color_t col_f = rgb(0, 123, 0);
color_t col_g = rgb(255, 0, 0);
color_t col_h = rgb(0, 0, 123);
color_t col_i = rgb(123, 0, 0);
color_t col_j = rgb(0, 123, 123);

// assets
string BORDERS		= "x240zx240zx240zx240zx240zx240zx240zx240zx28cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccbx28zx28ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccbax28zx28ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccaax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaax28zx28baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaax28zx240zx240zx240zx240zx240zx240zx240zx28cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccbx28zx28ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccbax28zx28ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccaax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cccx179aax28zx28cbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaax28zx28baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaax28zx240zx240zx240zx240zx240zx240zx240zx240z";

string BACKGROUND	= "bbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczbbbbbbbbbbbbbbbbbbbczccccccccccccccccccccz";
string BUTTON		= "aaaaaaaaaaaaaaaaaaabzaaaaaaaaaaaaaaaaaabczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczaabbbbbbbbbbbbbbbbcczabcccccccccccccccccczbcccccccccccccccccccz";
string MINE			= "xxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxdxxxxxxxxxxzxxxxxxxxxdxxxxxxxxxxzxxxxxdxdddddxdxxxxxxzxxxxxxdddddddxxxxxxxzxxxxxddaadddddxxxxxxzxxxxxddaadddddxxxxxxzxxxdddddddddddddxxxxzxxxxxdddddddddxxxxxxzxxxxxdddddddddxxxxxxzxxxxxxdddddddxxxxxxxzxxxxxdxdddddxdxxxxxxzxxxxxxxxxdxxxxxxxxxxzxxxxxxxxxdxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxz";
string FLAG			= "xxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxggxxxxxxxxxzxxxxxxxggggxxxxxxxxxzxxxxxxgggggxxxxxxxxxzxxxxxxxggggxxxxxxxxxzxxxxxxxxxggxxxxxxxxxzxxxxxxxxxxdxxxxxxxxxzxxxxxxxxxxdxxxxxxxxxzxxxxxxxxddddxxxxxxxxzxxxxxxddddddddxxxxxxzxxxxxxddddddddxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxz";
string CURSOR		= "dddddddddddddddddddddzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxxxxxxxxxxxxxxxxxdzdxxxdxxxdxxxdxxxdxxddzdxdxxxdxxxdxxxdxxxdxdzddxdxdxdxdxdxdxdxdxddzdxdxdxdxdxdxdxdxdxdxdzdddddddddddddddddddddz";
string INCORRECT    = "xxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxggxxxxxxxxxggxxxxzxxxxggxxxxxxxggxxxxxzxxxxxggxxxxxggxxxxxxzxxxxxxggxxxggxxxxxxxzxxxxxxxggxggxxxxxxxxzxxxxxxxxgggxxxxxxxxxzxxxxxxxxgggxxxxxxxxxzxxxxxxxggxggxxxxxxxxzxxxxxxggxxxggxxxxxxxzxxxxxggxxxxxggxxxxxxzxxxxggxxxxxxxggxxxxxzxxxggxxxxxxxxxggxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxzxxxxxxxxxxxxxxxxxxxxz";
string HIT			= "gggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczgggggggggggggggggggczccccccccccccccccccccz";

string GAMEOVER		= "x4ggggggx6ggggx5gggx3gggx4ggggggggx17gggggx5gggx6ggx2ggggggggx3gggggggx3zx2gggggggggx4gggggx5gggx3gggx4ggggggggx16ggggggggx3gggx5gggx2ggggggggx3ggggggggx2zxggggx5gx4ggxggx5ggggxggggx4gggx20gggx3gggx3gggx5gggx2gggx8gggx3gggxzxgggx11ggxggx5ggggxggggx4gggx19gggx5gggx3ggx5ggx3gggx8gggx3gggxzgggx11gggxgggx4ggggxgxggx4gggx19gggx5gggx3gggx3gggx3gggx8gggx3gggxzgggx3gggggx3ggx3ggx4ggxgxgxggx4ggggggggx14gggx5gggx3gggx3gggx3ggggggggx3gggx2ggggxzgggx3gggggx3ggx3ggx4ggxgggxggx4ggggggggx14gggx5gggx4ggx3ggx4ggggggggx3ggggggggx2zgggx5gggx2gggx3gggx3ggxgggxggx4gggx19gggx5gggx4gggxgggx4gggx8gggggggx3zgggx5gggx2gggggggggx3ggxggx2ggx4gggx19gggx5gggx4gggxgggx4gggx8gggx2gggx2zggggx4gggx2gggggggggx3ggx5ggx4gggx19gggx5gggx5ggxggx5gggx8gggx2gggx2zxggggx3gggxgggx5gggx2ggx5ggx4gggx20gggx3gggx6gggggx5gggx8gggx3gggxzx2gggggggggxggx6gggx2ggx5ggx4ggggggggx15ggggggggx7gggggx5ggggggggx3gggx3gggxzx4ggggggx2ggx7ggx2ggx5ggx4ggggggggx17gggggx9gggx6ggggggggx3gggx4gggzx107z";
string YOUWIN		= "dddx5dddx3dddddx5dddx4dddx14ddx6ddx3dddddddddx2ddddx3dddzcdddx3dddcx2ddddddddx3dddx4dddx14ddx6ddx3dddddddddx2ddddx3dddzxdddx3dddx2dddx3dddx3dddx4dddx14ddx6ddx3cccdddcccx2dddddx2dddzxcdddxdddcxdddx5dddx2dddx4dddx14ddx6ddx6dddx5dddddx2dddzx2dddxdddx2dddx5dddx2dddx4dddx14ddx2ddx2ddx6dddx5dddddx2dddzx2cddxddcx2dddx5dddx2dddx4dddx14ddxdddx2ddx6dddx5dddcddxdddzx3dddddx3dddx5dddx2dddx4dddx14ddxdcdx2ddx6dddx5dddxddxdddzx3cdddcx3dddx5dddx2dddx4dddx14ddxdxddxddx6dddx5dddxddxdddzx4dddx4dddx5dddx2dddx4dddx14ddxdxddxddx6dddx5dddxcdddddzx4dddx4dddx5dddx2dddx4dddx14ddddxcddddx6dddx5dddx2dddddzx4dddx4cdddx3dddcx2ddddx2ddddx14dddcx2ddddx6dddx5dddx2dddddzx4dddx5ddddddddcx3cddddddddcx14dddx3ddddx3dddddddddx2dddx2cddddzx4dddx5ccdddddcx5cddddddcx15dddx3cdddx3dddddddddx2dddx3ddddzx4cccx7cccccx7ccccccx16cccx4cccx3cccccccccx2cccx3ccccz";

string ONE			= "xxxxxeexxxzxxxxeeexxxzxxxeeeexxxzxxeeeeexxxzxxxxeeexxxzxxxxeeexxxzxxxxeeexxxzxxxxeeexxxzxxeeeeeeexzxxeeeeeeexz";
string TWO			= "xffffffffxzffffffffffzfffxxxxfffzxxxxxxxfffzxxxxxffffxzxxxfffffxxzxfffffxxxxzffffxxxxxxzffffffffffzffffffffffz";
string THREE		= "gggggggggxzggggggggggzxxxxxxxgggzxxxxxxxgggzxxxggggggxzxxxggggggxzxxxxxxxgggzxxxxxxxgggzggggggggggzgggggggggxz";
string FOUR			= "xxhhhxhhhxzxxhhhxhhhxzxhhhxxhhhxzxhhhxxhhhxzhhhhhhhhhhzhhhhhhhhhhzxxxxxxhhhxzxxxxxxhhhxzxxxxxxhhhxzxxxxxxhhhxz";
string FIVE			= "iiiiiiiiiiziiiiiiiiiiziiixxxxxxxziiixxxxxxxziiiiiiiiixziiiiiiiiiizxxxxxxxiiizxxxxxxxiiiziiiiiiiiiiziiiiiiiiixz";
string SIX			= "xjjjjjjjjxzjjjjjjjjjxzjjjxxxxxxxzjjjxxxxxxxzjjjjjjjjjxzjjjjjjjjjjzjjjxxxxjjjzjjjxxxxjjjzjjjjjjjjjjzxjjjjjjjjxz";
string SEVEN		= "ddddddddddzddddddddddzxxxxxxxdddzxxxxxxxdddzxxxxxxdddxzxxxxxxdddxzxxxxxdddxxzxxxxxdddxxzxxxxdddxxxzxxxxdddxxxz";
string EIGHT		= "xccccccccxzcccccccccczcccxxxxccczcccxxxxccczxccccccccxzxccccccccxzcccxxxxccczcccxxxxccczcccccccccczxccccccccxz";

string DISPLAY		= "dddddddddddddzdddididididddzdiddidididdidzddiddididdiddzdididddddididzddidddddddiddzdididddddididzddidddddddiddzdididddddididzddidddddddiddzdiddidididdidzdddididididddzdiddidididdidzddidddddddiddzdididddddididzddidddddddiddzdididddddididzddidddddddiddzdididddddididzddiddididdiddzdiddidididdidzdddididididddzdddddddddddddz";
string LSEG			= "gxxzggxzgggzgggzgggzgggzgggzggxzgxxz";
string RSEG			= "xxgzxggzgggzgggzgggzgggzgggzxggzxxgz";
string USEG			= "gggggggggzxgggggggxzxxgggggxxz";
string DSEG			= "xxgggggxxzxgggggggxzgggggggggz";
string CSEG			= "xgggggggxzgggggggggzxgggggggxz";

// ============================================
//                 STRUCTURES
// ============================================

// details about a single mine tile
// flags:
//  flagged  - has this tile been flagged as a mine
//  revealed - has this tile been revealed
// values:
//  state    - the state of the current tile. -1 is
//             a mine. everything above -1 is the 
//             poximity to another mine
struct tile {
	bool flagged = false;
	bool revealed = false;
	int state = 0;
};

tile tiles[SIZE][SIZE]; // init our minefield as an array of tiles;

// useful vector struct inspired by picosystem examples
struct vect {
	int x, y;

	// shortcut function for getting vectors offset from this one
	// these will be particularly useful when percolating and initializing
	vect next(int dx, int dy) {
		return vect{ x + dx, y + dy };
	}

	int distance(vect other) {
		int dx = abs(other.x - x);
		int dy = abs(other.y - y);
		return dx > dy ? dx : dy;
	}

	// get a tile associated with the current vector x y values
	tile* tile() {
		return &tiles[y][x];
	}
};

// ============================================
//              HELPER FUNCTIONS
// ============================================

// helper to tell if x, y is in bounds
bool valid_tile(vect vec) {
	return vec.x >= 0 && vec.y >= 0 && vec.x < SIZE && vec.y < SIZE;
}

// generates a random coordinatw within 0-w and 0-h (
vect random_coord(int w, int h) {
	return vect{ rand() % w, rand() % h };
}

// convert a char to a palette color
color_t str_to_color(char s) {
	if (s == 'a') {
		return col_a;
	}
	if (s == 'b') {
		return col_b;
	}
	if (s == 'c') {
		return col_c;
	}
	if (s == 'd') {
		return col_d;
	}
	if (s == 'e') {
		return col_e;
	}
	if (s == 'f') {
		return col_f;
	}
	if (s == 'g') {
		return col_g;
	}
	if (s == 'h') {
		return col_h;
	}
	if (s == 'i') {
		return col_i;
	}
	if (s == 'j') {
		return col_j;
	}
}

// render a given asset
void render_asset(int x, int y, string str) {

	int tx = x;
	int ty = y;
	for (size_t i = 0; i < str.size(); ++i) {
		char c = str[i];

		// ignore all but color charas
		if (!isalpha(str[i])) {
			continue;
		}

		// we skip if x
		if (c == 'x') {

			// if there isnt a number ahead or if we are oob do the usual
			if (i+1 >= str.size() || isalpha(str[i+1])) {
				tx += 1;
				continue;
			}

			
			int q = i+1;
			string num = "";

			// build number char by char
			while (q < str.size() && !isalpha(str[q])) {
				num += str[q];
				q++;
			}

			int inum = std::stoi(num);
			tx += inum;
			continue;
		}

		// move to next row if z
		if (c == 'z') {
			ty += 1;
			tx = x;
			continue;
		}

		pen(str_to_color(c)); // set pen color
		pixel(tx, ty);

		tx += 1;
	}
}

// overload for render asset
void render_asset(vect pos, string str) {
	render_asset(pos.x, pos.y, str);
}

// convert a state int to an asset string
string state_to_string(int state) {
	if (state == 1) {
		return ONE;
	}
	if (state == 2) {
		return TWO;
	}
	if (state == 3) {
		return THREE;
	}
	if (state == 4) {
		return FOUR;
	}
	if (state == 5) {
		return FIVE;
	}
	if (state == 6) {
		return SIX;
	}
	if (state == 7) {
		return SEVEN;
	}
	if (state == 8) {
		return EIGHT;
	}
	return "";
}

// single segment display, can be set to show a negative sign
// this is to be used exclusively with multi seg display
struct seg_display {
	int digit = 0;
	bool minus = false;

	void render(vect pos) {
		digit = digit % 10; // make sure digit is 0-9

		render_asset(pos, DISPLAY); // render background

		// a minus is not a number and is only one seg
		if (minus) {
			render_asset(pos.next(2, 10), CSEG);
			return;
		}
		
		// segment display logic, split by segment
		if (digit != 1 && digit != 4) {
			render_asset(pos.next(2, 1), USEG);
		}
		if (digit == 0 || digit > 3 && digit != 7) {
			render_asset(pos.next(1, 2), LSEG);
		}
		if (digit != 5 && digit != 6) {
			render_asset(pos.next(9, 2), RSEG);
		}
		if (digit > 1 && digit != 7) {
			render_asset(pos.next(2, 10), CSEG);
		}
		if (digit % 2 == 0 && digit != 4) {
			render_asset(pos.next(1, 12), LSEG);
		}
		if (digit != 2) {
			render_asset(pos.next(9, 12), RSEG);
		}
		if (digit != 1 && digit != 4 && digit != 7) {
			render_asset(pos.next(2, 19), DSEG);
		}
	}
};

struct multi_seg_display {
	int segs = 3;
	int value = 0;

	void render(vect pos) {

		int tval = abs(value);
		for (int i = 0; i < segs; ++i) {
			// create segment and update digit
			seg_display seg;
			seg.digit = tval % 10;

			// if we're at the last seg and a negative number
			// render a minus instead.
			if (value < 0 && i + 1 == segs) {
				seg.minus = true;
			}

			seg.render(pos.next((segs-i-1) * 13, 0));

			// move on to next digit
			tval = tval / 10;
		}
	}
};

// ============================================
//          GAME ESSENTIAL FUNCTIONS
// ============================================


bool fresh = true;  // keeps track of if new game was started
vect cursor = vect{0, 0};  // cursor position
int hidden_tiles = 0; // number of tiles remaining
int mines_remaining = 0; // number of mines remaining
int game_state = 0; // game state

// reset and start a new game.
void new_game() {

    game_state  = 0;
	fresh = true;
	cursor = vect{ 0, 0 };
	hidden_tiles = SIZE * SIZE;
	mines_remaining = MINES;
	
	// reset the previous minefield
	for (int y = 0; y < SIZE; ++y) {
		for (int x = 0; x < SIZE; ++x) {
			tiles[y][x] = tile();
		}
	}

	// it may seem counterintuitive but we actually
	// do not generate our minefield here, we generate
	// it when the user first clicks on a tile. this is
	// because the first tile the user clicks on must 
	// never be a mine.
}

void generate_minefield(vect mask) {

	// let's drop some mines
	for (int i = 0; i < MINES; ++i) {
		tile* selected = nullptr;
		vect pos;

		// look for a place to put our mine until we find one
		do {
			// get our random position
			pos = random_coord(SIZE, SIZE);
			selected = pos.tile();

			// if there's already a mine there we try again
			if (selected->state < 0) {
				continue;
			}

			// make sure that a mine cannot be placed within the 
			// surrounding 8 tiles of the first click
			if (mask.distance(pos) <= 1) {
				continue;
			}

			// mine pos is valid, exit loop
			break;
		} while (true);

		selected->state = -1;

		// update neighboring tiles
		for (int y = -1; y <= 1; ++y) {
			for (int x = -1; x <= 1; ++x) {

				// dont update our own tile
				if (x == 0 && y == 0) {
					continue;
				}

				// get neighbor vect
				vect offset = pos.next(x, y);

				// dont update oob tiles
				if (!valid_tile(offset)) {
					continue;
				}

				// get neighbor tile
				tile* neighbor = offset.tile();

				// dont update mines
				if (neighbor->state < 0) {
					continue;
				}

				// update this tile
				neighbor->state += 1;
			}
		}
	}
}

bool reveal_at(vect pos) {

	if (fresh) {
		generate_minefield(pos);
		fresh = false;
	}

	// get our tile
	tile* sel = pos.tile();

	// no need to reveal an already revealed tile
	if (sel->revealed) {
		return false;
	}

	// reveal our tile
	sel->revealed = true;
	hidden_tiles -= 1;

	// if its a number stop revealing
	if (sel->state > 0) {
		return false;
	}

	// if its a mine we stop revealing and die. 
	// this condition can never be hit through
	// percolation. This condition can only ever
	// be hit if the user selected a mine
	if (sel->state < 0) {
		return true;
	}

	// reveal neighboring zeroes
	bool exploded = false;
	for (int y = -1; y <= 1; ++y) {
		for (int x = -1; x <= 1; ++x) {
			
			// no need to reveal own tile
			if (x == 0 && y == 0) {
				continue;
			}

			// get neighbor vect
			vect offset = pos.next(x, y);

			// dont reveal oob tiles
			if (!valid_tile(offset)) {
				continue;
			}

			// get neighbor tile
			tile* neighbor = offset.tile();

			// do not reveal mines
			// this condition should never be triggered
			// but itll be here just in case
			if (neighbor->state < 0) {
				continue;
			}

			// reveal neighbor tile
			reveal_at(offset);
		}
	}
	return false;
}

void init() {
	srand(time(nullptr));
	new_game();
}

void draw(bool show_all = false, bool dead = false) {
	system("cls");
	cout << "Board:" << endl;

	// color board back
	pen(col_b);
	frect(0, 0, 240, 240);

	// render game state
	if (show_all) {
		if (dead) {
			render_asset(87, 18, GAMEOVER);
		}
		else {
			render_asset(87, 18, YOUWIN);
		}
	}

	int offx = 31;
	int offy = 51;

	// draw minefield
	for (int y = 0; y < SIZE; ++y) {
		for (int x = 0; x < SIZE; ++x) {
			tile* tile = &tiles[y][x];

			int tx = x * 20 + offx;
			int ty = y * 20 + offy;

			// process flags
			if (!tile->revealed && !show_all) {
				render_asset(tx, ty, BACKGROUND);
				render_asset(tx-1, ty-1, BUTTON);
				cout << "? ";

				if (tile->flagged) {
					render_asset(tx-1, ty-1, FLAG);
				}

			}
			else if (tile->flagged && show_all) {

				// correctly flagged mines dont get revealed
				if (tile->state < 0) {
					render_asset(tx, ty, BACKGROUND);
					render_asset(tx-1, ty-1, BUTTON);
					render_asset(tx-1, ty-1, FLAG);
				}

				// incorrectly flagged tiles are revealed
				if (tile->state >= 0) {
					render_asset(tx, ty, BACKGROUND);
					render_asset(tx, ty, MINE);
					render_asset(tx, ty, INCORRECT);
				}
			}

			// draw revealed mines
			else if (tile->state < 0) {
				
				if (dead && x == cursor.x && y == cursor.y) {
					render_asset(tx, ty, HIT);
				}
				else {
					render_asset(tx, ty, BACKGROUND);
				}

				render_asset(tx, ty, MINE);

				cout << "* ";
			}

			// draw numeric states
			else {
				render_asset(tx, ty, BACKGROUND);
				render_asset(tx+5, ty+5, state_to_string(tile->state));
				cout << tile->state << " ";
			}
		}
		cout << endl;
	}

	// render borders
	render_asset(0, 0, BORDERS);

	// render cursor
	if (!show_all) {
		render_asset(cursor.x * 20 + offx - 1, cursor.y * 20 + offy - 1, CURSOR);
	}

	// render flag count
	multi_seg_display flagcount;
	flagcount.value = mines_remaining;
	flagcount.render(vect{34, 14});
}

bool win() {
	return hidden_tiles == MINES;
}

// important game data initialized here
void init() {
	srand(time(nullptr));
	new_game();
}

// function to process inputs, update state
void update(uint32_t tick) {

    // have user hit A to reset the game after a loss / win
    if (game_state > 1) {
         if (pressed(A)) {
            new_game();
         }
         return;
    }

    if (pressed(UP) && valid_tile(cursor.next(0, -1))) {
        cursor = cursor.next(0, -1);
        return;
    }
    if (pressed(DOWN) && valid_tile(cursor.next(0, 1))) {
        cursor = cursor.next(0, 1);
        return;
    }
    if (pressed(LEFT) && valid_tile(cursor.next(-1, 0))) {
        cursor = cursor.next(-1, 0);
        return;
    }
    if (pressed(RIGHT) && valid_tile(cursor.next(1, 0))) {
        cursor = cursor.next(1, 0);
        return;
    }

    if (pressed(A)) {
        bool bad = reveal_at(cursor);

        // end the game with a loss
        if (bad) {
            game_state = 2
            return;
        }

        // end the game with a win
        if (win()) {
            game_state = 3
            return;
        }
    }

    if (pressed(B)) {
        cursor.tile()->flagged = !cursor.tile()->flagged; // invert flagged state
        if (cursor.tile()->flagged) {
            mines_remaining -= 1;
        }
        else {
            mines_remaining += 1;
        }
        return;
    }
}

// drawing function
void draw(uint32_t tick) {
    
    // normal drawing operation
    if (game_state < 2) {
        draw();
    } 

    // loss state drawing
    if (game_state == 2) {
        draw(true, true);
    }

    // win state drawing
    if (game_state == 3) {
        draw(true);
    }
}