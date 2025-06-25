#pragma once

#include <string> // Used for text
#include "Estroimpl.h"
#include "Estrolist.h"
#include "Estrotypes.h"
#include "Estronodes.h"

//!The default Estroengine namespace.
namespace Estro {
	/*!@brief The class used by Estroengine for running code.
	 *
	 * Derive this class to create your own Nodes to add to the engine.
	 */


	/*!@brief A basic Node to be able to manage the global program state.
	 *
	 *Always intended to be the root of the tree.
	 */
	class Engine : public Node {
		public:
			void step() override;
			void draw() override;
			void update();

			/*!
			 * @brief Clean up all the accumulated garbage in memory.
			 *
			 * It is unlikely you will need to call this function directly, as it is done automatically every frame during the engine's update() function.
			 */
			void garbageCollect();

		protected:


		private:

	};
}