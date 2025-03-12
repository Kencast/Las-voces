/**
 * Simulated annealing
 * Robado de la pandilla
 */

#include "rng.cpp"

struct Timer {
	using time = my_clock::time_point;
	time start = my_clock::now();
	double elapsed() { // Segundos desde el inicio.
		time now = my_clock::now();
		return chrono::duration<double>(now - start).count();
	}
} timer;

template<class See,class Upd>struct Annealing {
	using energy = invoke_result_t<See>;
	energy curr, low;
	See see; // lambda
	Upd upd; // lambda
	Annealing(See _see, Upd _upd): see{_see}, upd{_upd}
		{curr = low = see(), upd();}
	void simulate(double s, double mult=1) { // Simula por `s` segundos.
		double t0 = timer.elapsed();
		for (double t = t0; t-t0 < s; t = timer.elapsed()) {
			energy near = see();
			auto delta = double(curr - near);
			if (delta >= 0) upd(), curr = near, low = min(low, curr);
			else {
				double temp = mult * (1 - (t-t0)/s);
				if (exp(delta/temp) > rng.real()) upd(), curr = near;
			}
		}
	}
};
