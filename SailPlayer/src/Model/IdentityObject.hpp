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

		IdentityObject(IdentityObject& object) : _id(object.GetID())
		{
		}

		inline int GetID() { return _id; }
		inline void SetID(int id) { _id = id; }

	private:
		int _id;
	};
}

#endif // IDENTITYOBJECT_HPP
