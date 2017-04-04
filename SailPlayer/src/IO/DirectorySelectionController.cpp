#include <QQmlEngine>

#include "FileHelper.hpp"
#include "DirectorySelectionController.hpp"

namespace IO
{
	DirectorySelectionController::DirectorySelectionController(FsRecordInfoFactory* recordFactory)
		: _recordFactory(recordFactory)
	{
		QQmlEngine::setObjectOwnership(this, QQmlEngine::JavaScriptOwnership);

		_model = new FsRecordsListModel(this);

		SetDirectoryPath("/");
	}

	void DirectorySelectionController::SetDirectoryPath(QString directoryPath)
	{
		if (directoryPath == _directoryPath)
			return;

		if(!FileHelper::Exists(directoryPath))
			return;

		_directoryPath = PreprocessDirectoryPath(directoryPath);

		_model->DeleteItems();

		_model->AddItems(_recordFactory->CreateList(_directoryPath));

		emit DirectoryPathChanged();
	}

	QString DirectorySelectionController::PreprocessDirectoryPath(QString directoryPath)
	{
		// Processing ".." file name to correctly handle directory-up functionality
		if(directoryPath.endsWith("/.."))
		{
			directoryPath = directoryPath.mid(0, directoryPath.indexOf("/.."));

			if(directoryPath != "")
				directoryPath = directoryPath.mid(0, directoryPath.lastIndexOf("/"));

			if(directoryPath == "")
				directoryPath = "/";
		}

		return directoryPath;
	}
}
