#pragma once

#include <string> // Used for text
#include "Estroimpl.h"
#include "Estrolist.h"
#include "Estrocolors.h"
#include "Estrotypes.h"
#include "Estroinput.h"

//!The default Estroengine namespace.
namespace Estro {
	/*!@brief The class used by Estroengine for running code.
	 *
	 * Derive this class to create your own Nodes to add to the engine.
	 */
	class Node {
		public:
			Node* parent = nullptr; // nullptr is used when a value is not yet set. This can be checked by going, for example, if (parent) {//codegoeshere}

			/*!@brief An overridable function for the step event that is triggered every frame (input, movement, etc).*/
			virtual void step();
			/*!@brief An overridable function for the draw event that is triggered every frame (textures, lines, etc).*/
			virtual void draw();
			/*!@brief An overridable function for when the node is created.*/
			virtual void onCreate();
			/*!@brief An overridable function for when the node is removed from the tree.*/
			virtual void onDestroy();

			/*!@brief Get a list of all the immediate children of this Node.*/
			List<Node*> getChildren();
			/*!@brief Get a list of all the ancestors of this Node (parents and onwards).*/
			List<Node*> getAncestors();
			/*!@brief Get a list of all the siblings of this Node.
			 *
			 * The node itself is automatically removed from the list.
			 */
			List<Node*> getSiblings();
			/*!@brief Get a list of all the descendants of this Node (children and onwards).*/
			List<Node*> getDescendants();

			/*!@brief Get a list of all the immediate children of this Node with a specific tag.*/
			List<Node*> getChildrenTagged(const std::string &tag);
			/*!@brief Get a list of all the ancestors of this Node (parents and onwards).*/
			List<Node*> getAncestorsTagged(const std::string &tag);
			/*!@brief Get a list of all the siblings of this Node.
			 *
			 * The node itself is automatically removed from the list.
			*/
			List<Node*> getSiblingsTagged(const std::string &tag);
			/*!@brief Get a list of all the descendants of this Node (children and onwards).*/
			List<Node*> getDescendantsTagged(const std::string &tag);

			/*!@brief Get a pointer to a single child in this Node with a specific tag.
			 *
			 * Will return `nullptr` if the tag is not found.
			 */
			Node* getChildTagged(const std::string &tag);

			/*!@brief Get a pointer to a single ancestor (children and onwards) with a specific tag.
			 *
			 * Will return `nullptr` if the tag is not found.
			 */
			Node* getAncestorTagged(const std::string &tag);

			/*!@brief Get a pointer to a single sibling with a specific tag.
			 *
			 *The node itself is automatically removed from the list.
			 *Will return `nullptr` if the tag is not found.
			 */
			Node* getSiblingTagged(const std::string &tag);

			/*!@brief Get a pointer to a single descendant with a specific tag.
			 *
			 *Will return `nullptr` if the tag is not found.
			 */
			Node* getDescendantTagged(const std::string &tag);

			/*!@brief Removes the node from the tree.*/
			void destroy();

			void destroyChildTagged(const std::string &tag);
			void destroyAncestorTagged(const std::string &tag);
			void destroySiblingTagged(const std::string &tag);
			void destroyDescendantTagged(const std::string &tag);

			void destroyChildrenTagged(const std::string &tag);
			void destroyAncestorsTagged(const std::string &tag);
			void destroySiblingsTagged(const std::string &tag);
			void destroyDescendantsTagged(const std::string &tag);

			/*!@brief Add a tag to this node.
			 *
			 *Will not add the same tag more than once.
			 */
			void addTag(const std::string &tag);
			/*!@brief Remove a tag from this node.*/
			void removeTag(const std::string &tag);
			/*!@brief Check if this node has a specific tag*/
			bool hasTag(const std::string &tag);
			/*!@brief Get a list of all this Node's tags.*/
			List<std::string> getTags();

			/*!@brief Add a new Node to the children of this one.*/
			template <typename nodeType>
			nodeType* addNode() {
				nodeType* node = new nodeType;
				_children.add(node);

				node->onCreate();

				return node;
			}

			/*!@brief Climbs up the tree until it hits the top and returns the root node.*/
			Node* getRoot();

			//unsigned int getHandle();

		private:


		protected:
			unsigned int _handle = 0; // TODO: Implement.
			List<Node*> _children;
			List<std::string> _tags;
	};

	/*!@brief A basic Node to be able to manage the global program state.
	 *
	 *Always intended to be the root of the tree.
	 */
	class Engine : public Node {
		public:
			void step() override;
			void draw() override;
			void update();

		protected:
			static void garbageCollect();

		private:

	};
}