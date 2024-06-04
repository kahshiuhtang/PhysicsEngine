#ifndef ATG_SIMPLE_2D_CONSTRAINT_SOLVER_RIGID_BODY_SYSTEM_H
#define ATG_SIMPLE_2D_CONSTRAINT_SOLVER_RIGID_BODY_SYSTEM_H

#include "rigid_body.hpp"
#include "constraint.hpp"
#include "force_gen.hpp"
#include "matrix.hpp"
//#include "sparse_matrix.h"
#include "state.hpp"

#include <vector>

namespace Engine {
    class RigidBodySystem {
        public:
            static const int ProfilingSamples = 60 * 10;

        public:
            RigidBodySystem();
            virtual ~RigidBodySystem();

            virtual void reset();
            virtual void process(double dt, int steps = 1);

            void addRigidBody(RigidBody *body);
            void removeRigidBody(RigidBody *body);
            RigidBody *getRigidBody(int i);

            void addConstraint(Constraint *constraint);
            void removeConstraint(Constraint *constraint);

            void addForceGenerator(ForceGenerator *generator);
            void removeForceGenerator(ForceGenerator *generator);

            int getRigidBodyCount() const { return (int)m_rigidBodies.size(); }
            int getConstraintCount() const { return (int)m_constraints.size(); }
            int getForceGeneratorCount() const { return (int)m_forceGenerators.size(); }

            int getFullConstraintCount() const;

            float getOdeSolveMicroseconds() const;
            float getConstraintSolveMicroseconds() const;
            float getForceEvalMicroseconds() const;
            float getConstraintEvalMicroseconds() const;

            inline const Engine::State *state() const { return &m_state; }

        protected:
            static float findAverage(long long *samples);

            void populateSystemState();
            void populateMassMatrices(MathEngine::Matrix *M, MathEngine::Matrix *M_inv);
            void processForces();

        protected:
            std::vector<RigidBody *> m_rigidBodies;
            std::vector<Constraint *> m_constraints;
            std::vector<ForceGenerator *> m_forceGenerators;

            Engine::State m_state;

            long long *m_odeSolveMicroseconds;
            long long *m_constraintSolveMicroseconds;
            long long *m_forceEvalMicroseconds;
            long long *m_constraintEvalMicroseconds;
            long long m_frameIndex;
    };
} 

#endif