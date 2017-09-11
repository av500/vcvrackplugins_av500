#include "av500.hpp"

struct av500Plugin : Plugin {
	av500Plugin() {
		slug = "av500";
		name = "av500";
		createModel<MultipleWidget>(this, "av500 Multiple", "Multiples");
	}
};


Plugin *init() {
	return new av500Plugin();
}
