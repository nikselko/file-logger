/******************************************************************************
*                                                                             *
*   Program : FileLogger                                                      *
*                                                                             *
*   Date : 15 / 04 / 2021                                                     *
*                                                                             *
*   Programmer : Nikita Seliverstov (nikselko)                                *
*                                                                             *
*                                                                             *
******************************************************************************/

#include "DynamicArray.h"
#include "Logger.h"

int main()
{
	{// DybamycArray Test
		DynamicArray da1{ 1024 * 768 };
		std::cout << "Instances: " << da1.tracker().instances()
			<< " memory: " << da1.tracker().memory() << "\n";
		DynamicArray da2{ 1024 * 255 };
		std::cout << "Instances: " << da2.tracker().instances()
			<< " memory: " << da2.tracker().memory() << "\n";
		{
			DynamicArray da3{ 128 };
			std::cout << "Instances: " << da3.tracker().instances()
				<< " memory: " << da3.tracker().memory() << "\n";
		}
		std::cout << "Instances: " << DynamicArray::tracker().instances()
			<< " memory: " << DynamicArray::tracker().memory() << "\n";
	}
	
	
	{// FileWrite Test
		FileWriter fw{ "test.txt" };

		fw.write("Alice has ").then(3).then(" rats.").newline();

		std::cout << "Written " << fw.size() << " chars and " << fw.lines() << " lines.\n";

		fw.write("True of false: does Alice like rats?\n")
			.then("Answer: ")
			.then(true)
			.then("\n");

		std::cout << "Written " << fw.size() << " chars and " << fw.lines() << " lines.\n";

		fw.~FileWriter();
	}


	{// Logger Test
		Logger::get().log("Hello, we are running!");
	}
}
