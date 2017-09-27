#include "av500.hpp"

Plugin *plugin;

void init(rack::Plugin *p) {
	plugin = p;
	plugin->slug = "av500";
	plugin->name = "av500";
	createModel<MultipleWidget>(plugin, "av500 Multiple",    "Triple Multiple");
	createModel<Blank8hpWidget>(plugin, "av500 8hp Blank",   "8hp Blank");
	createModel<p0wrWidget>    (plugin, "av500 p0wr",        "p0wr");
	createModel<TR808CowbellWidget>
	                           (plugin, "av500 808Cowbell",  "808Cowbell");
}
