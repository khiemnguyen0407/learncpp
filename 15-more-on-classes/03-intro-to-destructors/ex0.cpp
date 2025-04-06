/* The cleanup problem */

/*
Let’s say that you are writing a program that needs to send some data over a network. However, 
establishing a connection to the server is expensive, so you want to collect a bunch of data and 
then send it all at once. Such a class might be structured like this.

// This example won't compile because it is (intentionally) incomplete
class NetworkData
{
private:
    std::string server_name{};
    DataStore data_queue{};

public:
	NetworkData(std::string_view server_name)
		: server_name { server_name }
	{
	}

	void add_data(std::string_view data)
	{
		data_queue.add(data);
	}

	void send_data()
	{
		// connect to server
		// send all data
		// clear data
	}
};

int main()
{
    NetworkData n("someipAddress");

    n.add_data("somedata1");
    n.add_data("somedata2");

    n.send_data();

    return 0;
}

However, this NetworkData has a potential issue. It relies on send_data() being explicitly called 
before the program is shut down. If the user of NetworkData forgets to do this, the data will not 
be sent to the server, and will be lost when the program exits. Now, you might say, "well, it is 
not hard to remember to do this!", and in this particular case, you would be right. But consider a 
slightly more complex example, like this function:

bool do_something()
{
    NetworkData n("someipAddress");

    n.add_data("somedata1");
    n.add_data("somedata2");

    if (someCondition)
        return false;

    n.send_data();
    return true;
}

In this case, if some_condition is true, then the function will return early, and send_data() will 
not be called. This is an easier mistake to make, because the send_data() call is present, the 
program just isn't pathing to it in all cases.

To generalize this issue, classes that use a resource (most often memory, but sometimes files, 
databases, network connections, etc…) often need to be explicitly sent or closed before the class 
object using them is destroyed. In other cases, we may want to do some record-keeping prior to the 
destruction of the object, such as writing information to a log file, or sending a piece of 
telemetry to a server. The term “clean up” is often used to refer to any set of tasks that a class 
must perform before an object of the class is destroyed in order to behave as expected. If we have 
to rely on the user of such a class to ensure that the function that performs clean up is called 
prior to the object being destroyed, we are likely to run into errors somewhere.

But why are we even requiring the user to ensure this? If the object is being destroyed, then we 
know that cleanup needs to be performed at that point. Should that cleanup happen automatically?

Now, you know the one of many purposes of "destructors"! Move on to continue on what they are and 
how we use them.
*/