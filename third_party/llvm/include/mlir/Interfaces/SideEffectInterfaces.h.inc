/*===- TableGen'erated file -------------------------------------*- C++ -*-===*\
|*                                                                            *|
|* Interface Declarations                                                     *|
|*                                                                            *|
|* Automatically generated file, do not edit!                                 *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

namespace mlir {
class MemoryEffectOpInterface;
namespace detail {
struct MemoryEffectOpInterfaceInterfaceTraits {
  struct Concept {
    void (*getEffects)(const Concept *impl, ::mlir::Operation *, ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> &);
  };
  template<typename ConcreteOp>
  class Model : public Concept {
  public:
    using Interface = ::mlir::MemoryEffectOpInterface;
    Model() : Concept{getEffects} {}

    static inline void getEffects(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> & effects);
  };
  template<typename ConcreteOp>
  class FallbackModel : public Concept {
  public:
    using Interface = ::mlir::MemoryEffectOpInterface;
    FallbackModel() : Concept{getEffects} {}

    static inline void getEffects(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> & effects);
  };
  template<typename ConcreteModel, typename ConcreteOp>
  class ExternalModel : public FallbackModel<ConcreteModel> {
  public:
    using ConcreteEntity = ConcreteOp;
  };
};template <typename ConcreteOp>
struct MemoryEffectOpInterfaceTrait;

} // namespace detail
class MemoryEffectOpInterface : public ::mlir::OpInterface<MemoryEffectOpInterface, detail::MemoryEffectOpInterfaceInterfaceTraits> {
public:
  using ::mlir::OpInterface<MemoryEffectOpInterface, detail::MemoryEffectOpInterfaceInterfaceTraits>::OpInterface;
  template <typename ConcreteOp>
  struct Trait : public detail::MemoryEffectOpInterfaceTrait<ConcreteOp> {};
  /// Collects all of the operation's effects into `effects`.
  void getEffects(::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> & effects);

    /// Collect all of the effect instances that correspond to the given
    /// `Effect` and place them in 'effects'.
    template <typename Effect> void getEffects(
      SmallVectorImpl<::mlir::SideEffects::EffectInstance<
                                              ::mlir::MemoryEffects::Effect>> &effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return !llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation exhibits the given effect.
    template <typename Effect> bool hasEffect() {
      SmallVector<SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return llvm::any_of(effects, [](const auto &it) {
        return llvm::isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation only has the given effect.
    template <typename Effect> bool onlyHasEffect() {
      SmallVector<SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return !effects.empty() && llvm::all_of(effects, [](const auto &it) {
        return isa<Effect>(it.getEffect());
      });
    }

    /// Returns true if this operation has no effects.
    bool hasNoEffect() {
      SmallVector<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      return effects.empty();
    }

    /// Returns true if the given operation has no effects for this interface.
    static bool hasNoEffect(Operation *op) {
      if (auto interface = dyn_cast<MemoryEffectOpInterface>(op))
        return interface.hasNoEffect();
      return op->hasTrait<::mlir::OpTrait::HasRecursiveSideEffects>();
    }

    /// Collect all of the effect instances that operate on the provided value
    /// and place them in 'effects'.
    void getEffectsOnValue(::mlir::Value value,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) { return it.getValue() != value; });
    }

    /// Return the effect of the given type `Effect` that is applied to the
    /// given value, or None if no effect exists.
    template <typename Effect>
    ::llvm::Optional<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>>
    getEffectOnValue(::mlir::Value value) {
      llvm::SmallVector<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>, 4> effects;
      getEffects(effects);
      auto it = llvm::find_if(effects, [&](auto &it) {
        return isa<Effect>(it.getEffect()) && it.getValue() == value;
      });
      if (it == effects.end())
        return llvm::None;
      return *it;
    }

    /// Collect all of the effect instances that operate on the provided symbol
    /// reference and place them in 'effects'.
    void getEffectsOnSymbol(::mlir::SymbolRefAttr value,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return it.getSymbolRef() != value;
      });
    }

    /// Collect all of the effect instances that operate on the provided
    /// resource and place them in 'effects'.
    void getEffectsOnResource(::mlir::SideEffects::Resource *resource,
              llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<
              ::mlir::MemoryEffects::Effect>> & effects) {
      getEffects(effects);
      llvm::erase_if(effects, [&](auto &it) {
        return it.getResource() != resource;
      });
    }
  
};
namespace detail {
  template <typename ConcreteOp>
  struct MemoryEffectOpInterfaceTrait : public ::mlir::OpInterface<MemoryEffectOpInterface, detail::MemoryEffectOpInterfaceInterfaceTraits>::Trait<ConcreteOp> {
  };
}// namespace detail
template<typename ConcreteOp>
void detail::MemoryEffectOpInterfaceInterfaceTraits::Model<ConcreteOp>::getEffects(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> & effects) {
  return (llvm::cast<ConcreteOp>(tablegen_opaque_val)).getEffects(effects);
}
template<typename ConcreteOp>
void detail::MemoryEffectOpInterfaceInterfaceTraits::FallbackModel<ConcreteOp>::getEffects(const Concept *impl, ::mlir::Operation *tablegen_opaque_val, ::llvm::SmallVectorImpl<::mlir::SideEffects::EffectInstance<::mlir::MemoryEffects::Effect>> & effects) {
  return static_cast<const ConcreteOp *>(impl)->getEffects(tablegen_opaque_val, effects);
}
} // namespace mlir
