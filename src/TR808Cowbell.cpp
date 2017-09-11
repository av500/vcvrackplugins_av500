#include "av500.hpp"
#include "CB_data.h"

struct TR808Cowbell : Module {
	enum ParamIds {
		NUM_PARAMS
	};
	enum InputIds {
		TRIG_INPUT,
		NUM_INPUTS
	};
	enum OutputIds {
		AUDIO_OUTPUT,
		NUM_OUTPUTS
	};

	SchmittTrigger trigger;
	
	unsigned int count = -1;
	
	TR808Cowbell();
	void step();
};

TR808Cowbell::TR808Cowbell() 
{
	params.resize(NUM_PARAMS);
	inputs.resize(NUM_INPUTS);
	outputs.resize(NUM_OUTPUTS);
	
	trigger.setThresholds(0.0, 1.0);
	
	// disarm
	count  = CB_s16_raw_len;


}

void TR808Cowbell::step() 
{
	if (trigger.process(getf(inputs[TRIG_INPUT]))) {
		count = 0;
	}
		
	if( count < CB_s16_raw_len ) {
		int16_t sample;
		sample  = CB_s16_raw[count++];
		sample |= CB_s16_raw[count++] << 8;
		
		setf(outputs[AUDIO_OUTPUT], 5.0 * (float)sample / 65536 );
	} else {
		setf(outputs[AUDIO_OUTPUT], 0.0 );
	}
}

TR808CowbellWidget::TR808CowbellWidget() 
{
	TR808Cowbell *module = new TR808Cowbell();
	setModule(module);
	box.size = Vec(15 * 4, 380);

	{
		Panel *panel = new LightPanel();
		panel->backgroundImage = Image::load("plugins/av500/res/TR808Cowbell.png");
		panel->box.size = box.size;
		addChild(panel);
	}

	addChild(createScrew<ScrewSilver>(Vec(15,   0)));
	addChild(createScrew<ScrewSilver>(Vec(15, 365)));
	
	addInput (createInput <PJ3410Port>(Vec( 0, 300), module, TR808Cowbell::TRIG_INPUT));
	addOutput(createOutput<PJ3410Port>(Vec(30, 300), module, TR808Cowbell::AUDIO_OUTPUT));

}
