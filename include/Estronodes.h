#pragma once
#include <string>

#include "Estrolist.h"
#include "Estrotypes.h"

namespace  Estro {
	class Node {
		public:
		virtual ~Node() = default;

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

	/*!@brief A basic Node with a 2D position.*/
	class Node2D : public Node {
	public:
		Vector2<float> position;

		void step() override {};
		void draw() override {};
	};

	/*!@brief A basic Node with a 3D position.*/
	class Node3D : public Node {
	public:
		Vector3<float> position;

		void step() override {};
		void draw() override {};
	};
}