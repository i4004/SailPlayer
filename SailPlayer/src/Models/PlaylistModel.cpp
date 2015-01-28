#include "PlaylistModel.h"

namespace Models
{
	PlaylistModel::PlaylistModel(QObject* parent)
	{
		Q_UNUSED(parent);
	}

	PlaylistModel::~PlaylistModel()
	{
		Cleanup();
	}

	void PlaylistModel::Cleanup()
	{
		while (!_tracksList.isEmpty())
			 delete _tracksList.takeFirst();
	}

	int PlaylistModel::rowCount(const QModelIndex &parent) const
	{
		Q_UNUSED(parent);

		return _tracksList.count();
	}

	QVariant PlaylistModel::data(const QModelIndex &index, int role) const
	{
		if (!index.isValid() || index.row() > _tracksList.size() - 1)
			return QVariant();

		// TODO

		return QVariant();
	}
}
