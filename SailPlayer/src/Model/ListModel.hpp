#ifndef LISTMODEL_HPP
#define LISTMODEL_HPP

#include <QAbstractListModel>

namespace Model
{
	template <class T>
	class ListModel : public QAbstractListModel
	{
	public:
		explicit ListModel(QObject* parent = nullptr) : QAbstractListModel(parent)
		{
			_rolesNames = QAbstractListModel::roleNames();
		}

		~ListModel()
		{
			DeleteItems();
		}

		// Items control

		void AddItem(T* item)
		{
			beginInsertRows(QModelIndex(), _items.count(), _items.count());

			_items.append(item);

			endInsertRows();
		}

		void AddItems(QList<T*> items)
		{
			if(items.count() == 0)
				return;

			beginInsertRows(QModelIndex(), _items.count(), _items.count() + items.count() - 1);

			_items.append(items);

			endInsertRows();
		}

		const QList<T*> GetItems() { return _items; }
		virtual QVariant GetItemData(int role, T* item) const = 0;

		void RefreshItem(T* item)
		{
			RefreshItem(GetItemIndex(item));
		}

		void DeleteItem(T* item)
		{
			DeleteItem(GetItemIndex(item));
		}

		void DeleteItems()
		{
			beginResetModel();

			while (!_items.isEmpty())
				delete _items.takeFirst();

			endResetModel();
		}

		// List View service methods

		int rowCount(const QModelIndex &parent = QModelIndex()) const
		{
			Q_UNUSED(parent);

			return _items.count();
		}

		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const
				{
			if (!index.isValid() || index.row() >= _items.count())
				return QVariant();

			return GetItemData(role, _items.at(index.row()));
		}

		QHash<int, QByteArray> roleNames() const { return _rolesNames; }

	protected:
		// Items control

		int GetItemIndex(T* item)
		{
			return _items.indexOf(item);
		}

		void RefreshItem(int itemIndex)
		{
			emit dataChanged(index(itemIndex) , index(itemIndex));
		}

		void DeleteItem(int itemIndex)
		{
			beginRemoveRows(QModelIndex(), itemIndex, itemIndex);

			delete _items.takeAt(itemIndex);

			endRemoveRows();
		}

		// Roles control

		void AddRole(int id, QByteArray name)
		{
			_rolesNames.insert(id, name);
		}

	private:
		QList<T*> _items;
		QHash<int, QByteArray> _rolesNames;
	};
}

#endif // LISTMODEL_HPP
