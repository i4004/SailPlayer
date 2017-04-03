#include "FileHelper.hpp"
#include "FsRecordsListModel.hpp"

namespace IO
{
	enum FsRecordsListModelRoles
	{
		NameRole = Qt::UserRole + 1,
		IsDirectoryRole = Qt::UserRole + 2,
		FilePathRole = Qt::UserRole + 3,
		IconNameRole = Qt::UserRole + 4,
//		AbsolutePathRole = Qt::UserRole + 5,
//		DirPathRole = Qt::UserRole + 6
	};

	FsRecordsListModel::FsRecordsListModel(QObject *parent) : ListModel<FsRecordInfo>(parent)
	{
		AddRole(NameRole, QByteArray("name"));
		AddRole(IsDirectoryRole, QByteArray("isDirectory"));
		AddRole(FilePathRole, QByteArray("filePath"));
		AddRole(IconNameRole, QByteArray("iconName"));

//		_rolesNames.insert(AbsolutePathRole, QByteArray("absolutePath"));
//		_rolesNames.insert(DirPathRole, QByteArray("dirPath"));
	}

	FsRecordsListModel::~FsRecordsListModel()
	{
	}

	QVariant FsRecordsListModel::GetItemData(int role, FsRecordInfo* item) const
	{
		switch (role)
		{
			case Qt::DisplayRole:

			case NameRole:
				return item->GetName();

			case IsDirectoryRole:
				return item->IsDirectory();

			case FilePathRole:
				return item->GetFilePath();

			case IconNameRole:
				return FileHelper::GetFsRecordIconName(*item);

			default:
				return QVariant();
		}
	}
}
