var init: f32 = 0;

export function test(length: i32, offset: i32): f32 {
	return load<f32>(offset << 2);
}

export function get(offset: i32): f32 {
	return load<f32>(offset << 2);
}

export function max(length: i32, init2: f32): f32 {
	for (let i: i32 = 0; i < length; ++i) {
		const value = load<f32>(i << 2);
		if (init < value) {
			init = value;
		}
	}
	return init;
}

/*
 * Auto Gain Analysis from ffmpeg- *
 * Ported from C to Typescript
 *
 * Original C Sourse:
 * https://github.com/avuserow/ffmpeg-blob/master/gain_analysis.c
 *
 */

const YULE_ORDER: u32 = 10;
const BUTTER_ORDER: u32 = 2;
const RMS_PERCENTILE: f32 = 0.95; // percentile which is louder than the proposed level
const MAX_SAMP_FREQ: f32 = 48000; // maximum allowed sample frequency [Hz]
const RMS_WINDOW_TIME: f32 = 0.05; // Time slice size [s]
const STEPS_per_dB: f32 = 100; // Table entries per dB
const MAX_dB: i32 = 120; // Table entries for 0...MAX_dB (normal max. values are 70...80 dB)

const MAX_ORDER: i32 = BUTTER_ORDER > YULE_ORDER ? BUTTER_ORDER : YULE_ORDER;
const MAX_SAMPLES_PER_WINDOW: u32 = <u32>floor(MAX_SAMP_FREQ * RMS_WINDOW_TIME); // max. Samples per Time slice
const PINK_REF: f32 = 64.82; //298640883795                              // calibration value

const ABYule: Array<Float32Array> = [
	new Float32Array(21),
	new Float32Array(21),
	new Float32Array(21),
	new Float32Array(21),
	new Float32Array(21),
	new Float32Array(21),
	new Float32Array(21),
	new Float32Array(21),
	new Float32Array(21)
];

ABYule[0][0] = 0.038575995713472366;
ABYule[0][1] = -3.8466460704803467;
ABYule[0][2] = -0.021603671833872795;
ABYule[0][3] = 7.815016746520996;
ABYule[0][4] = -0.0012339531676843762;
ABYule[0][5] = -11.341703414916992;
ABYule[0][6] = -0.00009291677997680381;
ABYule[0][7] = 13.055042266845703;
ABYule[0][8] = -0.016552602872252464;
ABYule[0][9] = -12.287598609924316;
ABYule[0][10] = 0.021615268662571907;
ABYule[0][11] = 9.482937812805176;
ABYule[0][12] = -0.0207404512912035;
ABYule[0][13] = -5.8725786209106445;
ABYule[0][14] = 0.005942980758845806;
ABYule[0][15] = 2.7546586990356445;
ABYule[0][16] = 0.003064280143007636;
ABYule[0][17] = -0.8698437809944153;
ABYule[0][18] = 0.00012025322212139145;
ABYule[0][19] = 0.13919314742088318;
ABYule[0][20] = 0.002884636865928769;
ABYule[1][0] = 0.054186563938856125;
ABYule[1][1] = -3.478459596633911;
ABYule[1][2] = -0.029110077768564224;
ABYule[1][3] = 6.36317777633667;
ABYule[1][4] = -0.008487094193696976;
ABYule[1][5] = -8.547514915466309;
ABYule[1][6] = -0.008511656895279884;
ABYule[1][7] = 9.476936340332031;
ABYule[1][8] = -0.008349909447133541;
ABYule[1][9] = -8.814987182617188;
ABYule[1][10] = 0.022452931851148605;
ABYule[1][11] = 6.854015350341797;
ABYule[1][12] = -0.02596338465809822;
ABYule[1][13] = -4.394710063934326;
ABYule[1][14] = 0.01624864898622036;
ABYule[1][15] = 2.1961169242858887;
ABYule[1][16] = -0.0024087904021143913;
ABYule[1][17] = -0.7510430216789246;
ABYule[1][18] = 0.006746137049049139;
ABYule[1][19] = 0.13149318099021912;
ABYule[1][20] = -0.0018776378128677607;
ABYule[2][0] = 0.154572993516922;
ABYule[2][1] = -2.378988265991211;
ABYule[2][2] = -0.09331049025058746;
ABYule[2][3] = 2.8486814498901367;
ABYule[2][4] = -0.06247880309820175;
ABYule[2][5] = -2.6457717418670654;
ABYule[2][6] = 0.021635418757796288;
ABYule[2][7] = 2.2369766235351562;
ABYule[2][8] = -0.05588393285870552;
ABYule[2][9] = -1.6714814901351929;
ABYule[2][10] = 0.04781476780772209;
ABYule[2][11] = 1.0059595108032227;
ABYule[2][12] = 0.0022231258917599916;
ABYule[2][13] = -0.45953458547592163;
ABYule[2][14] = 0.03174092620611191;
ABYule[2][15] = 0.16378164291381836;
ABYule[2][16] = -0.013905894011259079;
ABYule[2][17] = -0.05032077804207802;
ABYule[2][18] = 0.006514206528663635;
ABYule[2][19] = 0.023478973656892776;
ABYule[2][20] = -0.008813627064228058;
ABYule[3][0] = 0.3029690682888031;
ABYule[3][1] = -1.612731695175171;
ABYule[3][2] = -0.2261398881673813;
ABYule[3][3] = 1.0797749757766724;
ABYule[3][4] = -0.08587323874235153;
ABYule[3][5] = -0.25656259059906006;
ABYule[3][6] = 0.03282930329442024;
ABYule[3][7] = -0.1627671867609024;
ABYule[3][8] = -0.00915702898055315;
ABYule[3][9] = -0.22638893127441406;
ABYule[3][10] = -0.02364141121506691;
ABYule[3][11] = 0.3912079930305481;
ABYule[3][12] = -0.005844560451805592;
ABYule[3][13] = -0.22138139605522156;
ABYule[3][14] = 0.06276101619005203;
ABYule[3][15] = 0.04500235244631767;
ABYule[3][16] = -0.000008280867405119352;
ABYule[3][17] = 0.020058518275618553;
ABYule[3][18] = 0.0020586189348250628;
ABYule[3][19] = 0.003024390898644924;
ABYule[3][20] = -0.029501350596547127;
ABYule[4][0] = 0.33642303943634033;
ABYule[4][1] = -1.4985897541046143;
ABYule[4][2] = -0.25572240352630615;
ABYule[4][3] = 0.8735027313232422;
ABYule[4][4] = -0.11828570067882538;
ABYule[4][5] = 0.1220502257347107;
ABYule[4][6] = 0.11921148747205734;
ABYule[4][7] = -0.8077494502067566;
ABYule[4][8] = -0.07834489643573761;
ABYule[4][9] = 0.47854796051979065;
ABYule[4][10] = -0.004699779208749533;
ABYule[4][11] = -0.12453458458185196;
ABYule[4][12] = -0.005895002279430628;
ABYule[4][13] = -0.04067510366439819;
ABYule[4][14] = 0.05724228173494339;
ABYule[4][15] = 0.08333755284547806;
ABYule[4][16] = 0.008320439606904984;
ABYule[4][17] = -0.042373478412628174;
ABYule[4][18] = -0.01635381393134594;
ABYule[4][19] = 0.029772073030471802;
ABYule[4][20] = -0.01760176569223404;
ABYule[5][0] = 0.44915255904197693;
ABYule[5][1] = -0.628206193447113;
ABYule[5][2] = -0.14351756870746613;
ABYule[5][3] = 0.2966178357601166;
ABYule[5][4] = -0.22784394025802612;
ABYule[5][5] = -0.3725637197494507;
ABYule[5][6] = -0.014191401191055775;
ABYule[5][7] = 0.002137678675353527;
ABYule[5][8] = 0.0407826267182827;
ABYule[5][9] = -0.42029818892478943;
ABYule[5][10] = -0.12398163229227066;
ABYule[5][11] = 0.2219965010881424;
ABYule[5][12] = 0.040975652635097504;
ABYule[5][13] = 0.006134243682026863;
ABYule[5][14] = 0.10478503257036209;
ABYule[5][15] = 0.06747620552778244;
ABYule[5][16] = -0.01863887719810009;
ABYule[5][17] = 0.05784820392727852;
ABYule[5][18] = -0.031934283673763275;
ABYule[5][19] = 0.032227542251348495;
ABYule[5][20] = 0.005419077351689339;
ABYule[6][0] = 0.5661947131156921;
ABYule[6][1] = -1.0480033159255981;
ABYule[6][2] = -0.7546445727348328;
ABYule[6][3] = 0.29156312346458435;
ABYule[6][4] = 0.16242137551307678;
ABYule[6][5] = -0.26805999875068665;
ABYule[6][6] = 0.1674424409866333;
ABYule[6][7] = 0.008199996314942837;
ABYule[6][8] = -0.18901604413986206;
ABYule[6][9] = 0.45054733753204346;
ABYule[6][10] = 0.30931782722473145;
ABYule[6][11] = -0.3303240239620209;
ABYule[6][12] = -0.27562960982322693;
ABYule[6][13] = 0.06739368289709091;
ABYule[6][14] = 0.006473106797784567;
ABYule[6][15] = -0.047842543572187424;
ABYule[6][16] = 0.08647503703832626;
ABYule[6][17] = 0.0163990780711174;
ABYule[6][18] = -0.03788984566926956;
ABYule[6][19] = 0.018073642626404762;
ABYule[6][20] = -0.00588215421885252;
ABYule[7][0] = 0.5810049772262573;
ABYule[7][1] = -0.5103532671928406;
ABYule[7][2] = -0.5317490696907043;
ABYule[7][3] = -0.31863564252853394;
ABYule[7][4] = -0.14289799332618713;
ABYule[7][5] = -0.20256413519382477;
ABYule[7][6] = 0.17520704865455627;
ABYule[7][7] = 0.14728154242038727;
ABYule[7][8] = 0.023779451847076416;
ABYule[7][9] = 0.3895263969898224;
ABYule[7][10] = 0.15558448433876038;
ABYule[7][11] = -0.2331327199935913;
ABYule[7][12] = -0.25344789028167725;
ABYule[7][13] = -0.052460189908742905;
ABYule[7][14] = 0.016284624114632607;
ABYule[7][15] = -0.025059618055820465;
ABYule[7][16] = 0.06920468062162399;
ABYule[7][17] = 0.024423573166131973;
ABYule[7][18] = -0.03721611574292183;
ABYule[7][19] = 0.018188010901212692;
ABYule[7][20] = -0.007496187929064035;
ABYule[8][0] = 0.536487877368927;
ABYule[8][1] = -0.2504987120628357;
ABYule[8][2] = -0.4216303527355194;
ABYule[8][3] = -0.43193942308425903;
ABYule[8][4] = -0.0027595360297709703;
ABYule[8][5] = -0.03424680978059769;
ABYule[8][6] = 0.04267842322587967;
ABYule[8][7] = -0.046783287078142166;
ABYule[8][8] = -0.1021486446261406;
ABYule[8][9] = 0.26408299803733826;
ABYule[8][10] = 0.14590772986412048;
ABYule[8][11] = 0.1511313021183014;
ABYule[8][12] = -0.02459864877164364;
ABYule[8][13] = -0.1755649298429489;
ABYule[8][14] = -0.11202315241098404;
ABYule[8][15] = -0.18823009729385376;
ABYule[8][16] = -0.04060034081339836;
ABYule[8][17] = 0.05477720499038696;
ABYule[8][18] = 0.04788665473461151;
ABYule[8][19] = 0.04704409837722778;
ABYule[8][20] = -0.022179368883371353;

const ABButter: Array<Float32Array> = [
	new Float32Array(5),
	new Float32Array(5),
	new Float32Array(5),
	new Float32Array(5),
	new Float32Array(5),
	new Float32Array(5),
	new Float32Array(5),
	new Float32Array(5),
	new Float32Array(5)
];

ABButter[0][0] = 0.986211895942688;
ABButter[0][1] = -1.972233772277832;
ABButter[0][2] = -1.972423791885376;
ABButter[0][3] = 0.9726139903068542;
ABButter[0][4] = 0.986211895942688;
ABButter[1][0] = 0.9850017428398132;
ABButter[1][1] = -1.9697785377502441;
ABButter[1][2] = -1.9700034856796265;
ABButter[1][3] = 0.9702284932136536;
ABButter[1][4] = 0.9850017428398132;
ABButter[2][0] = 0.9793893098831177;
ABButter[2][1] = -1.9583537578582764;
ABButter[2][2] = -1.9587786197662354;
ABButter[2][3] = 0.9592034816741943;
ABButter[2][4] = 0.9793893098831177;
ABButter[3][0] = 0.975318431854248;
ABButter[3][1] = -1.950027585029602;
ABButter[3][2] = -1.950636863708496;
ABButter[3][3] = 0.9512461423873901;
ABButter[3][4] = 0.975318431854248;
ABButter[4][0] = 0.9731652140617371;
ABButter[4][1] = -1.9456102848052979;
ABButter[4][2] = -1.9463304281234741;
ABButter[4][3] = 0.9470506906509399;
ABButter[4][4] = 0.9731652140617371;
ABButter[5][0] = 0.9645451307296753;
ABButter[5][1] = -1.927832841873169;
ABButter[5][2] = -1.9290902614593506;
ABButter[5][3] = 0.930347740650177;
ABButter[5][4] = 0.9645451307296753;
ABButter[6][0] = 0.9600914120674133;
ABButter[6][1] = -1.918589472770691;
ABButter[6][2] = -1.9201828241348267;
ABButter[6][3] = 0.9217761754989624;
ABButter[6][4] = 0.9600914120674133;
ABButter[7][0] = 0.9585691690444946;
ABButter[7][1] = -1.9154211282730103;
ABButter[7][2] = -1.9171383380889893;
ABButter[7][3] = 0.918855607509613;
ABButter[7][4] = 0.9585691690444946;
ABButter[8][0] = 0.9459768533706665;
ABButter[8][1] = -1.8890330791473389;
ABButter[8][2] = -1.891953706741333;
ABButter[8][3] = 0.8948743343353271;
ABButter[8][4] = 0.9459768533706665;

//(10 * 2+(48000*0.05 + 10) * 2)*2
const linprebuf: Float32Array = new Float32Array(MAX_ORDER * 2);
let linpre: u32 = 0; // left input samples, with pre-buffer
const lstepbuf: Float32Array = new Float32Array(MAX_SAMPLES_PER_WINDOW + MAX_ORDER);
let lstep: u32 = 0; // left "first step" (i.e. post first filter) samples
const loutbuf: Float32Array = new Float32Array(MAX_SAMPLES_PER_WINDOW + MAX_ORDER);
let lout: u32 = 0; // left "out" (i.e. post second filter) samples
const rinprebuf: Float32Array = new Float32Array(MAX_ORDER * 2);
let rinpre: u32 = 0; // right input samples ...
const rstepbuf: Float32Array = new Float32Array(MAX_SAMPLES_PER_WINDOW + MAX_ORDER);
let rstep: u32 = 0;
const routbuf: Float32Array = new Float32Array(MAX_SAMPLES_PER_WINDOW + MAX_ORDER);
let rout: u32 = 0;
let sampleWindow: i32 = 0; // number of samples required to reach number of milliseconds required for RMS window
let totsamp: i32 = 0;
let lsum: f32 = 0;
let rsum: f32 = 0;
let freqindex: i32 = 0;

let maxmem: u32 = 0;

const A: Uint32Array = new Uint32Array(<u32>(<u32>STEPS_per_dB * <u32>MAX_dB));
const B: Uint32Array = new Uint32Array(<u32>(<u32>STEPS_per_dB * <u32>MAX_dB));

//@inline
function loadf(pointer: u32): f32 {
	return pointer < maxmem ? load<f32>(pointer << 2) || 0 : 0;
}
//@inline
function storef(pointer: u32, value: f32): void {
	if (pointer < maxmem) store<f32>(pointer << 2, value);
}

function filterYule(input: u32, output: u32, nSamples: u32, kernel: Float32Array): void {
	while (nSamples--) {
		storef(
			output,
			1e-10 +
				loadf(input) * kernel[0] -
				loadf(output - 1) * kernel[1] +
				loadf(input - 1) * kernel[2] -
				loadf(output - 2) * kernel[3] +
				loadf(input - 2) * kernel[4] -
				loadf(output - 3) * kernel[5] +
				loadf(input - 3) * kernel[6] -
				loadf(output - 4) * kernel[7] +
				loadf(input - 4) * kernel[8] -
				loadf(output - 5) * kernel[9] +
				loadf(input - 5) * kernel[10] -
				loadf(output - 6) * kernel[11] +
				loadf(input - 6) * kernel[12] -
				loadf(output - 7) * kernel[13] +
				loadf(input - 7) * kernel[14] -
				loadf(output - 8) * kernel[15] +
				loadf(input - 8) * kernel[16] -
				loadf(output - 9) * kernel[17] +
				loadf(input - 9) * kernel[18] -
				loadf(output - 10) * kernel[19] +
				loadf(input - 10) * kernel[20]
		);
		++input;
		++output;
	}
}

function filterYuleRA(input: u32, output: Float32Array, op: u32, nSamples: u32, kernel: Float32Array): void {
	while (nSamples--) {
		output[op] =
			1e-10 +
			loadf(input) * kernel[0] -
			(output[op - 1] || 0) * kernel[1] +
			loadf(input - 1) * kernel[2] -
			(output[op - 2] || 0) * kernel[3] +
			loadf(input - 2) * kernel[4] -
			(output[op - 3] || 0) * kernel[5] +
			loadf(input - 3) * kernel[6] -
			(output[op - 4] || 0) * kernel[7] +
			loadf(input - 4) * kernel[8] -
			(output[op - 5] || 0) * kernel[9] +
			loadf(input - 5) * kernel[10] -
			(output[op - 6] || 0) * kernel[11] +
			loadf(input - 6) * kernel[12] -
			(output[op - 7] || 0) * kernel[13] +
			loadf(input - 7) * kernel[14] -
			(output[op - 8] || 0) * kernel[15] +
			loadf(input - 8) * kernel[16] -
			(output[op - 9] || 0) * kernel[17] +
			loadf(input - 9) * kernel[18] -
			(output[op - 10] || 0) * kernel[19] +
			loadf(input - 10) * kernel[20];
		++input;
		++op;
	}
}

function filterYuleAA(input: Float32Array, ip: u32, output: Float32Array, op: u32, nSamples: u32, kernel: Float32Array): void {
	while (nSamples--) {
		output[op] =
			1e-10 +
			(input[ip] || 0) * kernel[0] -
			(output[op - 1] || 0) * kernel[1] +
			(input[ip - 1] || 0) * kernel[2] -
			(output[op - 2] || 0) * kernel[3] +
			(input[ip - 2] || 0) * kernel[4] -
			(output[op - 3] || 0) * kernel[5] +
			(input[ip - 3] || 0) * kernel[6] -
			(output[op - 4] || 0) * kernel[7] +
			(input[ip - 4] || 0) * kernel[8] -
			(output[op - 5] || 0) * kernel[9] +
			(input[ip - 5] || 0) * kernel[10] -
			(output[op - 6] || 0) * kernel[11] +
			(input[ip - 6] || 0) * kernel[12] -
			(output[op - 7] || 0) * kernel[13] +
			(input[ip - 7] || 0) * kernel[14] -
			(output[op - 8] || 0) * kernel[15] +
			(input[ip - 8] || 0) * kernel[16] -
			(output[op - 9] || 0) * kernel[17] +
			(input[ip - 9] || 0) * kernel[18] -
			(output[op - 10] || 0) * kernel[19] +
			(input[ip - 10] || 0) * kernel[20];
		++ip;
		++op;
	}
}

function filterButter(input: u32, output: u32, nSamples: number, kernel: Float32Array): void {
	while (nSamples--) {
		storef(
			output,
			loadf(input) * kernel[0] -
				loadf(output - 1) * kernel[1] +
				loadf(input - 1) * kernel[2] -
				loadf(output - 2) * kernel[3] +
				loadf(input - 2) * kernel[4]
		);
		++input;
		++output;
	}
}

function filterButterAA(input: Float32Array, ip: u32, output: Float32Array, op: u32, nSamples: number, kernel: Float32Array): void {
	while (nSamples--) {
		output[op] =
			(input[ip] || 0) * kernel[0] -
			(output[op - 1] || 0) * kernel[1] +
			(input[ip - 1] || 0) * kernel[2] -
			(output[op - 2] || 0) * kernel[3] +
			(input[ip - 2] || 0) * kernel[4];
		++ip;
		++op;
	}
}

// returns a true if successful, false if not
function ResetSampleFrequency(samplefreq: u32): i32 {
	// zero out initial values
	for (let i: i32 = 0; i < MAX_ORDER; i++) {
		linprebuf[i] = lstepbuf[i] = loutbuf[i] = 0;
		rinprebuf[i] = rstepbuf[i] = routbuf[i] = 0;
	}

	switch (samplefreq) {
		case 48000:
			freqindex = 0;
			break;
		case 44100:
			freqindex = 1;
			break;
		case 32000:
			freqindex = 2;
			break;
		case 24000:
			freqindex = 3;
			break;
		case 22050:
			freqindex = 4;
			break;
		case 16000:
			freqindex = 5;
			break;
		case 12000:
			freqindex = 6;
			break;
		case 11025:
			freqindex = 7;
			break;
		case 8000:
			freqindex = 8;
			break;
		default:
			return -1;
	}

	sampleWindow = <i32>ceil(<f32>samplefreq * <f32>RMS_WINDOW_TIME);

	lsum = 0;
	rsum = 0;
	totsamp = 0;

	for (let i: i32 = 0; i < A.length; i++) {
		A[i] = 0;
	}

	return 0;
}

export function InitGainAnalysis(samplefreq: u32): i32 {
	if (ResetSampleFrequency(samplefreq) !== 0) {
		return -1;
	}

	linpre = MAX_ORDER;
	rinpre = MAX_ORDER;
	lstep = MAX_ORDER;
	rstep = MAX_ORDER;
	lout = MAX_ORDER;
	rout = MAX_ORDER;

	for (let i: i32 = 0; i < B.length; i++) {
		B[i] = 0;
	}

	return 0;
}

// returns true if successful, false if not

//@inline
function fsqr(d: f32): f32 {
	return d * d;
}

function memcpy(to: i32, from: i32, length: number): void {
	for (let p = 0; p < length; ++p) {
		storef(to + p, loadf(from + p));
	}
}

function memcpyRA(to: Float32Array, offset: i32, from: i32, length: number): void {
	//trace('memcpyRA', to.length, offset, from, length);
	//for (let p = 0; p < length; ++p) {
	//	to[offset + p] = loadf(from + p);
	//}
}

function memcpyAA(to: Float32Array, offset: i32, from: Float32Array, offset2: i32, length: number): void {
	for (let p = 0; p < length; ++p) {
		to[offset + p] = from[offset2 + p];
	}
}

export function AnalyzeSamples(left_samples: u32, right_samples: u32): i32 {
	let curleft: u32 = 0;
	let curright: u32 = 0;
	let batchsamples: i32 = 0;
	let cursamples: i32 = 0;
	let cursamplepos: i32 = 0;
	let i: u32 = 0;
	const num_samples: i32 = right_samples;
	maxmem = num_samples * 2;

	if (num_samples === 0) return 111;

	batchsamples = num_samples;

	if (num_samples < MAX_ORDER) {
		memcpyRA(linprebuf, MAX_ORDER, left_samples, num_samples);
		memcpyRA(rinprebuf, MAX_ORDER, right_samples, num_samples);
	} else {
		memcpyRA(linprebuf, MAX_ORDER, left_samples, MAX_ORDER);
		memcpyRA(rinprebuf, MAX_ORDER, right_samples, MAX_ORDER);
	}

	while (batchsamples > 0) {
		cursamples = batchsamples > sampleWindow - totsamp ? sampleWindow - totsamp : batchsamples;
		if (cursamplepos < MAX_ORDER) {
			curleft = linpre + cursamplepos; // linprebuf pointer
			curright = rinpre + cursamplepos; // rinprebuf pointer
			if (cursamples > MAX_ORDER - cursamplepos) {
				cursamples = MAX_ORDER - cursamplepos;
			}

			filterYuleAA(linprebuf, curleft, lstepbuf, lstep + totsamp, cursamples, ABYule[freqindex]);
			filterYuleAA(rinprebuf, curright, rstepbuf, rstep + totsamp, cursamples, ABYule[freqindex]);
		} else {
			curleft = left_samples + cursamplepos; // ram pointer
			curright = right_samples + cursamplepos; // ram pointer

			filterYuleRA(curleft, lstepbuf, lstep + totsamp, cursamples, ABYule[freqindex]);
			filterYuleRA(curright, rstepbuf, rstep + totsamp, cursamples, ABYule[freqindex]);
		}

		filterButterAA(lstepbuf, lstep + totsamp, loutbuf, lout + totsamp, cursamples, ABButter[freqindex]);
		filterButterAA(rstepbuf, rstep + totsamp, routbuf, rout + totsamp, cursamples, ABButter[freqindex]);

		// Get the squared values
		curleft = lout + totsamp; // loutbuf pointer
		curright = rout + totsamp; // routbuf pointer

		i = cursamples % 16;
		while (i--) {
			lsum += fsqr(loutbuf[curleft]);
			curleft++;
			rsum += fsqr(routbuf[curright]);
			curright++;
		}
		i = <i32>(cursamples / 16);
		while (i--) {
			lsum +=
				fsqr(loutbuf[curleft + 0]) +
				fsqr(loutbuf[curleft + 1]) +
				fsqr(loutbuf[curleft + 2]) +
				fsqr(loutbuf[curleft + 3]) +
				fsqr(loutbuf[curleft + 4]) +
				fsqr(loutbuf[curleft + 5]) +
				fsqr(loutbuf[curleft + 6]) +
				fsqr(loutbuf[curleft + 7]) +
				fsqr(loutbuf[curleft + 8]) +
				fsqr(loutbuf[curleft + 9]) +
				fsqr(loutbuf[curleft + 10]) +
				fsqr(loutbuf[curleft + 11]) +
				fsqr(loutbuf[curleft + 12]) +
				fsqr(loutbuf[curleft + 13]) +
				fsqr(loutbuf[curleft + 14]) +
				fsqr(loutbuf[curleft + 15]);
			curleft += 16;
			rsum +=
				fsqr(routbuf[curright + 0]) +
				fsqr(routbuf[curright + 1]) +
				fsqr(routbuf[curright + 2]) +
				fsqr(routbuf[curright + 3]) +
				fsqr(routbuf[curright + 4]) +
				fsqr(routbuf[curright + 5]) +
				fsqr(routbuf[curright + 6]) +
				fsqr(routbuf[curright + 7]) +
				fsqr(routbuf[curright + 8]) +
				fsqr(routbuf[curright + 9]) +
				fsqr(routbuf[curright + 10]) +
				fsqr(routbuf[curright + 11]) +
				fsqr(routbuf[curright + 12]) +
				fsqr(routbuf[curright + 13]) +
				fsqr(routbuf[curright + 14]) +
				fsqr(routbuf[curright + 15]);
			curright += 16;
		}

		batchsamples -= cursamples;
		cursamplepos += cursamples;
		totsamp += cursamples;
		if (totsamp === sampleWindow) {
			// Get the Root Mean Square (RMS) for this set of samples
			const val: f32 = STEPS_per_dB * 10 * <f32>Math.log10(((lsum + rsum) / <f32>totsamp) * 0.5 + 1e-37);
			let ival: i32 = <i32>val;
			if (ival < 0) ival = 0;
			if (ival >= A.length) ival = A.length - 1;
			A[ival]++;
			lsum = rsum = 0;

			memcpyAA(loutbuf, lout, loutbuf, totsamp, MAX_ORDER);
			memcpyAA(routbuf, rout, routbuf, totsamp, MAX_ORDER);
			memcpyAA(lstepbuf, lstep, lstepbuf, totsamp, MAX_ORDER);
			memcpyAA(rstepbuf, rstep, rstepbuf, totsamp, MAX_ORDER);
			totsamp = 0;
		}
		if (totsamp > sampleWindow)
			// somehow I really screwed up: Error in programming! Contact author about totsamp > sampleWindow
			return 222;
	}
	if (num_samples < MAX_ORDER) {
		memcpyAA(linprebuf, 0, linprebuf, num_samples, MAX_ORDER - num_samples);
		memcpyAA(rinprebuf, 0, rinprebuf, num_samples, MAX_ORDER - num_samples);
		memcpyRA(linprebuf, MAX_ORDER - num_samples, left_samples, num_samples);
		memcpyRA(rinprebuf, MAX_ORDER - num_samples, right_samples, num_samples);
	} else {
		memcpyRA(linprebuf, 0, left_samples + num_samples - MAX_ORDER, MAX_ORDER);
		memcpyRA(rinprebuf, 0, right_samples + num_samples - MAX_ORDER, MAX_ORDER);
	}

	return 333;
}

function analyzeResult(array: Uint32Array, len: u32): f32 {
	let elems: u32;
	let upper: i32;
	let i: u32;

	elems = 0;
	for (i = 0; i < len; i++) elems += array[i];
	if (elems === 0) return -999999;

	upper = <i32>ceil(elems * (1.0 - RMS_PERCENTILE));
  trace('upper', elems, upper, len);
	for (i = len; i-- > 0; ) {
		if ((upper -= array[i]) <= 0) break;
	}

  trace('analyze', <i32>PINK_REF, i, STEPS_per_dB);

	return <f32>PINK_REF - <f32>i / STEPS_per_dB;
}

export function GetTitleGain(): f32 {
	let retval: f32;
	let i: i32;

	retval = analyzeResult(A, A.length);

	for (i = 0; i < A.length; i++) {
		B[i] += A[i];
		A[i] = 0;
	}

	for (i = 0; i < MAX_ORDER; i++) {
		//left
		linprebuf[i] = lstepbuf[i] = loutbuf[i] = 0;
		//right
		rinprebuf[i] = rstepbuf[i] = routbuf[i] = 0;
	}

	totsamp = 0;
	lsum = rsum = 0;
	return retval;
}

export function GetAlbumGain(): number {
	return analyzeResult(B, B.length);
}
