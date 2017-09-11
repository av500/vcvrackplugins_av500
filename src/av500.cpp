#include "av500.hpp"

struct av500Plugin : Plugin {
	av500Plugin() {
		slug = "av500";
		name = "av500";
		createModel<MultipleWidget>  (this, "av500 Multiple", 	"Triple Multiple");
		createModel<Blank8hpWidget>  (this, "av500 8hp Blank", 	"8hp Blank");
		createModel<p0wrWidget>      (this, "av500 p0wr", 	"p0wr");
	}
};


Plugin *init() {
	return new av500Plugin();
}
