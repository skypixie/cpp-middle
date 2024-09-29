#pragma once

/*
* Singleton pattern can be used
* for interacting with file system, for example.
* Or in a hacker simulator type of game where
* you have an in-game computer that can interact
* with files on your real computer
*/

class FileSystem
{
public:
	static FileSystem& instance()
	{
		static FileSystem* instance_ = new FileSystem();
		return *instance_;
	}

	void Write() {}
	void Read() {}
	void Delete() {}

private:
	FileSystem() {}
};


void DeleteSystem()
{
	// Start deleting
	FileSystem::instance().Delete();
}

int main()
{
	// would work fine ??
	DeleteSystem();
	FileSystem::instance().Read();
}