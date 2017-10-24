#include "av500.hpp"

Plugin *plugin;

void init(rack::Plugin *p) {
	plugin = p;
	p->slug = "av500";
#ifdef VERSION
	p->version = TOSTRING(VERSION);
#endif
	p->addModel(createModel<MultipleWidget>    ("av500", "av500", "Multiple", "Multiple"));
	p->addModel(createModel<Blank8hpWidget>    ("av500", "av500", "Blank", "8hp Blank"));
	p->addModel(createModel<p0wrWidget>        ("av500", "av500", "Power", "p0wr"));
	p->addModel(createModel<TR808CowbellWidget>("av500", "av500", "Drum", "808Cowbell"));
}

//plugin->homepageUrl = "https://github.com/av500/vcvrackplugins_av500";
