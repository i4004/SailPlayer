#ifndef LISTMODEL_HPP
#define LISTMODEL_HPP

#include <QAbstractListModel>

namespace Model
{
	template <class T>
	class ListModel : public QAbstractListModel
	{
	public:
		explicit ListModel(QObject* parent = 0) : QAbstractListModel(parent)
		{
			_rolesNames = QAbstractListModel::roleNames();
		}

		~ListModel()
		{
			DeleteItems();
		}

		// List View methods

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

		inline QList<T*> GetItems() { return _items; }
		virtual QVariant GetItemData(int role, T* item) const = 0;

		void DeleteItem(int i)
		{
			beginRemoveRows(QModelIndex(), i, i);

			delete _items.takeAt(i);

			endRemoveRows();
		}

	protected:
		void DeleteItems()
		{
			while (!_items.isEmpty())
				delete _items.takeFirst();
		}

		QList<T*> _items;
		QHash<int, QByteArray> _rolesNames;
	};
}

#endif // LISTMODEL_HPP
