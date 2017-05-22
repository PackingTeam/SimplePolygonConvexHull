#include "AlgorithmFactory.h"

extern Algorithm* getMethodById(int id)
{
	switch (id) {
	case 0: // Sklansky 1972
		return (Algorithm*)new Sklansky72();
	case 1: // McCallum & Avis 1979
		return (Algorithm*)new McCallumAvis79();
	case 2: // Sklansky 1982
		return (Algorithm*)new Sklansky82();
	case 3: // ElGindy, Avis & Toussaint 1983
		return (Algorithm*)new ElGindyAvisToussaint83();
	case 4: // Lee 1983 - Graham & Yao 1983
		return (Algorithm*)new LeeGrahamYao83();
	case 5: // Ghosh & Shyamasundar 1983
		return (Algorithm*)new GhoshShyamasundar83();
	case 6: // Bhattacharya & ElGindy 1984
		return (Algorithm*)new BhattacharyaElGindy84();
	case 7: // Orlowski 1985
		return (Algorithm*)new Orlowski85();
	case 8: // Preparata & Shamos 1985
		return (Algorithm*)new PreparataShamos85();
	case 9: // Shin & Woo 1986
		return (Algorithm*)new ShinWoo86();
	case 10: // Melkman 1987
		return (Algorithm*)new Melkman87();
	}
}