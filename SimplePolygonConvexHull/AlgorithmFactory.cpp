#include "AlgorithmFactory.h"

extern Algorithm* getMethodById(int id)
{
	switch (id) {
	case 0: // Sklansky 1972
		return (Algorithm*)Sklansky72::Instance();
	case 1: // McCallum & Avis 1979
		return (Algorithm*)McCallumAvis79::Instance();
	case 2: // Sklansky 1982
		return (Algorithm*)Sklansky82::Instance();
	case 3: // ElGindy, Avis & Toussaint 1983
		return (Algorithm*)ElGindyAvisToussaint83::Instance();
	case 4: // Lee 1983 - Graham & Yao 1983
		return (Algorithm*)LeeGrahamYao83::Instance();
	case 5: // Ghosh & Shyamasundar 1983
		return (Algorithm*)GhoshShyamasundar83::Instance();
	case 6: // Bhattacharya & ElGindy 1984
		return (Algorithm*)BhattacharyaElGindy84::Instance();
	case 7: // Orlowski 1985
		return (Algorithm*)Orlowski85::Instance();
	case 8: // Preparata & Shamos 1985
		return (Algorithm*)PreparataShamos85::Instance();
	case 9: // Shin & Woo 1986
		return (Algorithm*)ShinWoo86::Instance();
	case 10: // Melkman 1987
		return (Algorithm*)Melkman87::Instance();
	}
}