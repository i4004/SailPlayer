#ifndef IDENTITYOBJECT_HPP
#define IDENTITYOBJECT_HPP

namespace Model
{
	class IdentityObject
	{
	public:
		IdentityObject(int id) : _id(id)
		{
		}

		inline int GetID() { return _id; }

	private:
		int _id;
	};
}

#endif // IDENTITYOBJECT_HPP
