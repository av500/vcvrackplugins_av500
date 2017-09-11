#include "av500.hpp"

struct Multiple : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		A_INPUT,
		B_INPUT,
		C_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		A1_OUTPUT,
		A2_OUTPUT,
		B1_OUTPUT,
		B2_OUTPUT,
		C1_OUTPUT,
		C2_OUTPUT,
		NUM_OUTPUTS
	};

	Multiple();
	void step();
};

Multiple::Multiple() 
{
	params.resize(NUM_PARAMS);
	inputs.resize(NUM_INPUTS);
	outputs.resize(NUM_OUTPUTS);
}

void Multiple::step() 
{
	float in1 = getf(inputs[A_INPUT]);
	float in2 = getf(inputs[B_INPUT]);
	float in3 = getf(inputs[C_INPUT]);

	setf(outputs[A1_OUTPUT], in1);
	setf(outputs[A2_OUTPUT], in1);
	
	setf(outputs[B1_OUTPUT], in2);
	setf(outputs[B2_OUTPUT], in2);
	
	setf(outputs[C1_OUTPUT], in3);
	setf(outputs[C1_OUTPUT], in3);
}

MultipleWidget::MultipleWidget() 
{
	Multiple *module = new Multiple();
	setModule(module);
	box.size = Vec(15 * 2, 380);

	{
		Panel *panel = new LightPanel();
		panel->backgroundImage = Image::load("plugins/av500/res/Multiple.png");
		panel->box.size = box.size;
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(15,   0)));
	addChild(createScrew<ScrewSilver>(Vec(15, 365)));

	addInput (createInput<PJ3410Port> (Vec(0,  18), module, Multiple::A_INPUT));
	addOutput(createOutput<PJ3410Port>(Vec(0,  54), module, Multiple::A1_OUTPUT));
	addOutput(createOutput<PJ3410Port>(Vec(0,  90), module, Multiple::A2_OUTPUT));

	addInput (createInput<PJ3410Port> (Vec(0, 139), module, Multiple::B_INPUT));
	addOutput(createOutput<PJ3410Port>(Vec(0, 175), module, Multiple::B1_OUTPUT));
	addOutput(createOutput<PJ3410Port>(Vec(0, 211), module, Multiple::B2_OUTPUT));

	addInput (createInput<PJ3410Port> (Vec(0, 260), module, Multiple::C_INPUT));
	addOutput(createOutput<PJ3410Port>(Vec(0, 296), module, Multiple::C1_OUTPUT));
	addOutput(createOutput<PJ3410Port>(Vec(0, 332), module, Multiple::C1_OUTPUT));
}
