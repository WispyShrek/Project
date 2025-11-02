/**
 * @file Command.h
 * @brief Defines the abstract base class for the Command design pattern.
 */
#ifndef COMMAND_H
#define COMMAND_H

/**
 * @class Command
 * @brief Abstract base class for commands in the Command Pattern.
 *
 * This class defines the interface for executing commands.
 * Concrete command classes must inherit from this class and implement the
 * `execute()` method. This allows for decoupling the object that invokes an
 * operation from the one that knows how to perform it.
 */
class Command {
public:
	/**
	 * @brief Virtual destructor.
	 *
	 * Ensures that the destructors of derived concrete command classes are
	 * called correctly when an object is deleted through a base class pointer.
	 */
	virtual ~Command() = default;
	/**
	 * @brief Pure virtual method to execute the command.
	 *
	 * This is the core method of the Command pattern. Concrete subclasses must
	 * override this method to provide the specific action to be performed.
	 */
	virtual void execute() = 0;
};

#endif
