#ifndef BASE64_H
#define BASE64_H

#include <vector>
#include <string>

// our encryption will use the base64 algorithm

namespace Base64
{
	std::string base64_encode(const std::string &);


	// 3 lines to scramble base64 encoding
	const std::string &SALT1 = "LM::TB::BB";
	const std::string &SALT2 = "_:/_77";
	const std::string &SALT3 = "line=boostedC++";

	// triple encode with base64 with slight modifications (arbitrary)
	std::string EncryptB64(std::string s)
	{
		s = SALT1 + s + SALT2 + SALT3;
		s = base64_encode(s);
		s.insert(7, SALT3);
		s += SALT1;
		s = base64_encode(s);
		s += SALT2 + SALT3 + SALT1;
		s = base64_encode(s);
		s.insert(1, "Ls");
		s.insert(7, "A");
		return s;
	}
}

#endif // BASE64_H