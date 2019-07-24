#ifndef POINCARE_CONDENSED_SUM_LAYOUT_NODE_H
#define POINCARE_CONDENSED_SUM_LAYOUT_NODE_H

#include <poincare/sum.h>
#include <poincare/layout_cursor.h>
#include <poincare/layout_helper.h>
#include <poincare/layout.h>
#include <poincare/serialization_helper.h>

namespace Poincare {

class CondensedSumLayoutNode /*final*/ : public LayoutNode {
public:
  using LayoutNode::LayoutNode;

  // Layout
  Type type() const override { return Type::CondensedSumLayout; }

  /* CondensedSumLayout is only used in apps/shared/sum_graph_controller.cpp, in
   * a view with no cursor. */
  void moveCursorLeft(LayoutCursor * cursor, bool * shouldRecomputeLayout) override { assert(false); }
  void moveCursorRight(LayoutCursor * cursor, bool * shouldRecomputeLayout) override { assert(false); }
  void moveCursorUp(LayoutCursor * cursor, bool * shouldRecomputeLayout, bool equivalentPositionVisited = false) override { assert(false); }
  void moveCursorDown(LayoutCursor * cursor, bool * shouldRecomputeLayout, bool equivalentPositionVisited = false) override { assert(false); }
  int serialize(char * buffer, int bufferSize, Preferences::PrintFloatMode floatDisplayMode, int numberOfSignificantDigits) const override {
    return SerializationHelper::Prefix(this, buffer, bufferSize, floatDisplayMode, numberOfSignificantDigits, Sum::s_functionHelper.name(), true);
  }

  LayoutNode * layoutToPointWhenInserting(Expression * correspondingExpression) override {
    assert(false);
    return this;
  }

  // TreeNode
  size_t size() const override { return sizeof(CondensedSumLayoutNode); }
  int numberOfChildren() const override { return 3; }
#if POINCARE_TREE_LOG
  virtual void logNodeName(std::ostream & stream) const override {
    stream << "CondensedSumLayout";
  }
#endif

protected:
  // LayoutNode
  KDSize computeSize() override;
  KDCoordinate computeBaseline() override;
  KDPoint positionOfChild(LayoutNode * child) override;
private:
  void render(KDContext * ctx, KDPoint p, KDColor expressionColor, KDColor backgroundColor) override {}
  LayoutNode * baseLayout() { return childAtIndex(0); }
  LayoutNode * subscriptLayout() { return childAtIndex(1); }
  LayoutNode * superscriptLayout() { return childAtIndex(2); }
};

class CondensedSumLayout final : public Layout {
public:
  static CondensedSumLayout Builder(Layout base, Layout subscript, Layout superscript) { return TreeHandle::FixedArityBuilder<CondensedSumLayout, CondensedSumLayoutNode>(ArrayBuilder<TreeHandle>(base, subscript, superscript).array(), 3); }
  CondensedSumLayout() = delete;
};

}

#endif
