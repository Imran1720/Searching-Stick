#pragma once
#include <Vector>

namespace Gameplay
{
	namespace Collections
	{
		class StickCollectionModel;
		class StickCollectionView;
		enum class SearchType;
		struct Stick;

		class StickCollectionController
		{
		private:
			StickCollectionModel* stick_collection_model;
			StickCollectionView* stick_collection_view;

			std::vector<Stick*> sticks;
			Collections::SearchType search_type;

			void initializeSticks();
			float calculateStickWidth();
			void updateSticksPosition();
			void resetSticksColor();
			void initializeSticksArray();
			float calculateStickHeight(int array_pos);

			void destroy();

		public:
			StickCollectionController();
			~StickCollectionController();

			void initialize();
			void update();
			void render();
			
			void reset();

			SearchType getSearchType();
			int getNumberOfSticks();

		};
	}
}