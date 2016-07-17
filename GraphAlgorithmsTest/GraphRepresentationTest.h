#pragma once

#include "GraphRepresentation.h"

#include <gtest/gtest.h>

class GraphRepresentationTest : public ::testing::Test
{
protected:

	virtual void SetUp()
	{
		representation = nullptr;
	}

	virtual void TearDown()
	{
		if (representation)
			delete representation;
	}

	GraphRepresentation* representation;
};
