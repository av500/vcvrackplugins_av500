#include "av500.hpp"

struct p0wr : Module {
	enum ParamIds {
		SWITCH_PARAM,
		NUM_PARAMS
	};
	enum InputIds {
		NUM_INPUTS
	};
	enum OutputIds {
		NUM_OUTPUTS
	};

	p0wr();
	void step();
	
	float LEDs[3] = {};

};

p0wr::p0wr() 
{
	params.resize(NUM_PARAMS);
	inputs.resize(NUM_INPUTS);
	outputs.resize(NUM_OUTPUTS);
}

void p0wr::step() 
{
	switch ((int)roundf(params[SWITCH_PARAM])) {
		case 0: 
			LEDs[0] = 0;
			LEDs[1] = 0;
			LEDs[2] = 0;
			break;
		case 1: 
			LEDs[0] = 1;
			LEDs[1] = 2;
			LEDs[2] = 3;
			break;
	}
}

struct p0wrModeLight : ModeValueLight {
	p0wrModeLight() {
		addColor(COLOR_BLACK_TRANSPARENT);
		addColor(COLOR_RED);
		addColor(COLOR_YELLOW);
		addColor(COLOR_BLUE);
	}
};

p0wrWidget::p0wrWidget() 
{
	p0wr *module = new p0wr();
	setModule(module);
	box.size = Vec(15 * 4, 380);

	{
		Panel *panel = new LightPanel();
		panel->backgroundImage = Image::load("plugins/av500/res/p0wr.png");
		panel->box.size = box.size;
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(15,   0)));
	addChild(createScrew<ScrewSilver>(Vec(15, 365)));
	
	addParam(createParam<NKK>(Vec(14, 129), module, p0wr::SWITCH_PARAM, 0.0, 1.0, 0.0));
	
	addChild(createValueLight<LargeLight<p0wrModeLight>>(Vec(20,  51), &module->LEDs[0]));
	addChild(createValueLight<LargeLight<p0wrModeLight>>(Vec(20,  75), &module->LEDs[1]));
	addChild(createValueLight<LargeLight<p0wrModeLight>>(Vec(20, 100), &module->LEDs[2]));
}
