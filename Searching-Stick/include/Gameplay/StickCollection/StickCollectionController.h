#pragma once
#include <Vector>
#include <thread>
#include <SFML/Graphics.hpp>

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

			std::thread search_thread;

			Stick* stick_to_search;

			int number_of_comparisons;
			int number_of_array_access;

			int current_operation_delay;

			sf::String time_complexity;
			
			void initializeSticks();
			float calculateStickWidth();
			void updateSticksPosition();
			void resetSticksColor();
			void initializeSticksArray();
			float calculateStickHeight(int array_pos);

			void resetSearchStick();
			void shuffleSticks();

			void processLinearSearch();
			void processBinarySearch();

			void processSearchThreadState();

			void resetVariables();
			void destroy();
			void joinThreads();

			bool compareElementsByData(const Stick* stick1,const Stick* stick2) const;
			void sortElements();

		public:
			StickCollectionController();
			~StickCollectionController();

			void initialize();
			void update();
			void render();
			
			void reset();

			void searchElement(SearchType search_type);
			int getNumberOfComparision();
			int getNumberOfArrayAccess();

			SearchType getSearchType();
			int getNumberOfSticks();

			sf::String getTimeComplexity();

			int getDelayMillseconds();

		};
	}
}