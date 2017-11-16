#ifndef SRC_HyperParams_H_
#define SRC_HyperParams_H_

#include "N3LDG.h"
#include "Options.h"

using namespace nr;
using namespace std;

struct HyperParams {
	dtype nnRegular; // for optimization
	dtype adaAlpha;  // for optimization
	dtype adaEps; // for optimization
	dtype dropProb;
	dtype clips;
	dtype delta;

	string root = "ROOT";
	int rootID;
	int actionNum;
	int actionDim;
	int wordDim;
	int hiddenSize;
	int rnnHiddenSize;
	int maxlength;
	int batch;

	Alphabet wordAlpha;
	Alphabet actionAlpha;
	Alphabet labelAlpha;

public:
	HyperParams() {
		bAssigned = false;
	}

	void setRequared(Options &opt) {
		bAssigned = true;
		nnRegular = opt.regParameter;
		adaAlpha = opt.adaAlpha;
		adaEps = opt.adaEps;
		dropProb = opt.dropProb;
		hiddenSize = opt.hiddenSize;
		rnnHiddenSize = opt.rnnHiddenSize;
		batch = opt.batchSize;
		clips = opt.clips;
		delta = opt.delta;
	}

	void clear() {
		bAssigned = false;
	}

	bool bValid() {
		return bAssigned;
	}

	void print() {}


private:
	bool bAssigned;
};

#endif /* HyperParams_H_ */