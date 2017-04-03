#ifndef FSRECORDSLISTMODEL_HPP
#define FSRECORDSLISTMODEL_HPP

#include "../Model/ListModel.hpp"
#include "FsRecordInfo.hpp"

using namespace Model;

namespace IO
{
	class FsRecordsListModel : public ListModel<FsRecordInfo>
	{
		Q_OBJECT

	public:
		explicit FsRecordsListModel(QObject *parent = nullptr);
		~FsRecordsListModel();

		// Service methods
		QVariant GetItemData(int role, FsRecordInfo* item) const;
	};
}

#endif // FSRECORDSLISTMODEL_HPP
