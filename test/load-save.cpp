/* This tests saving and loading messages,
 * via files, streams and strings.
 */

#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

#include <mimesis.hpp>

using namespace std;

static bool load_save(const Mimesis::Message &msg) {
	// Save to and load from file
	{
		msg.save("load-save.tmp");
		Mimesis::Message msg2;
		msg2.load("load-save.tmp");

        if (msg2 != msg)
            std::cout << "Save to and load from file failed";

		assert(msg2 == msg);
	}

	// Save to and load from string
	{
		string str = msg.to_string();
		Mimesis::Message msg2;
		msg2.from_string(str);

        if (msg2 != msg)
            cout << "Save to and load from string failed";

		assert(msg2 == msg);
	}

	// Save to and load from stream using operators
	{
		stringstream ss;
		ss << msg;
		Mimesis::Message msg2;
		ss >> msg2;

        if (msg2 != msg)
            cout << "Save to and load from stream using operators failed";

		assert(msg2 == msg);
	}

	return true;
}


int main(int argc, char *argv[]) {
    printf(argv[0]);
    
    if (argc <= 1) {
		Mimesis::Message msg;
		msg.load(cin);
		return load_save(msg) ? 0 : 1;
	}

	for (int i = 1; i < argc; i++) {
        printf(argv[i]);

        ifstream in(argv[i]);

        if (!in.is_open())
            printf("failed to open");
        else
            in.close();

		Mimesis::Message msg;
		msg.load(argv[i]);
		if (!load_save(msg))
			return 1;

	}

	return 0;
}
