#include "../../PluginProcessor.h"

class MixGroupsTest : public UnitTest
{
public:
    MixGroupsTest() : UnitTest ("MixGroupsTest")
    {
    }

    void runTest() override
    {
        beginTest ("Dummy Test");
        std::cout << "Testing..." << std::endl;

        expect (false, "This SHOULD fail!");
    }
};

static MixGroupsTest mixGroupsTest;
