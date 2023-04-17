
/* Extension of queue:  thread safe */

#include <thread>
#include <queue>
#include <deque>
#include <mutex>
using namespace std;
template <class T>
class queueTs
{
private:
	queue<T> _q;

public:
	/**
	 * \brief 
	 * inserts element at the end
	 * 
	 * */
	void push(T &val)
	{
		std::lock_guard<std::mutex> qGuard(qMutex);
		_q.push(val);
	}

	/**
	 * \brief inserts element at the end
	 */
	void push(const T &val)
	{
		std::lock_guard<std::mutex> qGuard(qMutex);
		_q.push(val);
	}

	/**
	 * \brief removes the first element
	 */
	const T *pop()
	{
		std::lock_guard<std::mutex> qGuard(qMutex);
		T *ret = nullptr;
		if (!_q.empty())
		{
			T *ret = new T(_q.front());
			_q.pop();
		}
		else
		{
			 // @todo: may I've forgotten to save something?? :-(
		}

		return ret;
	}

	/**
	 * \brief constructs element in-place at the end
	 */
	decltype(auto) emplace(T &_Val)
	{
		std::lock_guard<std::mutex> qGuard(qMutex);
		return _q.emplace(_Val);
	}

	/**
	 * \brief checks whether the underlying container is empty
	 */
	bool empty()
	{
		std::lock_guard<std::mutex> qGuard(qMutex);
		return _q.empty();
	}

	/**
	 * \brief returns reference to the first element in the queue.
	 */
	const T &front()
	{
		std::lock_guard<std::mutex> qGuard(qMutex);
		return (_q.front());
	}

	/**
	 * \brief  returns reference to the last element in the queue.
	 */
	const T &back()
	{
		std::lock_guard<std::mutex> qGuard(qMutex);
		return (_q.back());
	}

protected:
	std::mutex qMutex;
};