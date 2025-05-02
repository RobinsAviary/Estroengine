#pragma once

#include <string> // Used for text
#include "Estrodefs.h" // Used for TemplateType
#include "Estrolist.h" // Used for lists
#include "Estrocolors.h"

namespace Estro {
	class Node {
		public:
			Node* parent = NULL; // NULL is used when a value is not yet set. This can be checked by going, for example, if (parent) {//codegoeshere}
			
			virtual void step();
			virtual void draw();
			virtual void onCreate();
			virtual void onDestroy();

			inline List<Node*> getChildren() { return children; }

			List<Node*> getAncestors();
			List<Node*> getSiblings();
			List<Node*> getDescendants();

			inline unsigned int getHandle() { return _handle; }

			List<Node*> children;
			List<std::string> tags;

		private:


		protected:
			unsigned int _handle = 0;
	};

	class Engine : public Node {
		public:
			void step();
			void draw();
			void update();

		protected:


		private:

	};
}