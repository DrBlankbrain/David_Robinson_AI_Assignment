#ifndef PARAMLOADER
#define PARAMLOADER
#pragma warning(disable:4800)
//------------------------------------------------------------------------
//
//Name:  ParamLoader.h
//
//Desc:  singleton class to handle the loading of default parameter
//       values from an initialization file: 'params.ini'
//
//Author: Mat Buckland 2003 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include <fstream>
#include <string>
#include <cassert>


#include "constants.h"
#include "misc/iniFileLoaderBase.h"

#define Prm2 (*ParamLoader::Instance2())
#define Prm (*ParamLoader::Instance())

class ParamLoader : public iniFileLoaderBase
{
private:
	
		ParamLoader() :iniFileLoaderBase("Params.ini")
		{

			GoalWidth = GetNextParameterDouble();

			NumSupportSpotsX = GetNextParameterInt();
			NumSupportSpotsY = GetNextParameterInt();

			Spot_PassSafeScore = GetNextParameterDouble();
			Spot_CanScoreFromPositionScore = GetNextParameterDouble();
			Spot_DistFromControllingPlayerScore = GetNextParameterDouble();
			Spot_ClosenessToSupportingPlayerScore = GetNextParameterDouble();
			Spot_AheadOfAttackerScore = GetNextParameterDouble();

			SupportSpotUpdateFreq = GetNextParameterDouble();

			ChancePlayerAttemptsPotShot = GetNextParameterDouble();
			ChanceOfUsingArriveTypeReceiveBehavior = GetNextParameterDouble();

			BallSize = GetNextParameterDouble();
			BallMass = GetNextParameterDouble();
			Friction = GetNextParameterDouble();

			KeeperInBallRange = GetNextParameterDouble();
			PlayerInTargetRange = GetNextParameterDouble();
			PlayerKickingDistance = GetNextParameterDouble();
			PlayerKickFrequency = GetNextParameterDouble();


			PlayerMass = GetNextParameterDouble();
			PlayerMaxForce = GetNextParameterDouble();
			PlayerMaxSpeedWithBall = GetNextParameterDouble();
			PlayerMaxSpeedWithoutBall = GetNextParameterDouble();
			PlayerMaxTurnRate = GetNextParameterDouble();
			PlayerScale = GetNextParameterDouble();
			PlayerComfortZone = GetNextParameterDouble();
			PlayerKickingAccuracy = GetNextParameterDouble();

			NumAttemptsToFindValidStrike = GetNextParameterInt();



			MaxDribbleForce = GetNextParameterDouble();
			MaxShootingForce = GetNextParameterDouble();
			MaxPassingForce = GetNextParameterDouble();

			WithinRangeOfHome = GetNextParameterDouble();
			WithinRangeOfSupportSpot = GetNextParameterDouble();

			MinPassDist = GetNextParameterDouble();
			GoalkeeperMinPassDist = GetNextParameterDouble();

			GoalKeeperTendingDistance = GetNextParameterDouble();
			GoalKeeperInterceptRange = GetNextParameterDouble();
			BallWithinReceivingRange = GetNextParameterDouble();

			bStates = GetNextParameterBool();
			bIDs = GetNextParameterBool();
			bSupportSpots = GetNextParameterBool();
			bRegions = GetNextParameterBool();
			bShowControllingTeam = GetNextParameterBool();
			bViewTargets = GetNextParameterBool();
			bHighlightIfThreatened = GetNextParameterBool();

			FrameRate = GetNextParameterInt();

			SeparationCoefficient = GetNextParameterDouble();
			ViewDistance = GetNextParameterDouble();
			bNonPenetrationConstraint = GetNextParameterBool();


			BallWithinReceivingRangeSq = BallWithinReceivingRange * BallWithinReceivingRange;
			KeeperInBallRangeSq = KeeperInBallRange * KeeperInBallRange;
			PlayerInTargetRangeSq = PlayerInTargetRange * PlayerInTargetRange;
			PlayerKickingDistance += BallSize;
			PlayerKickingDistanceSq = PlayerKickingDistance * PlayerKickingDistance;
			PlayerComfortZoneSq = PlayerComfortZone * PlayerComfortZone;
			GoalKeeperInterceptRangeSq = GoalKeeperInterceptRange * GoalKeeperInterceptRange;
			WithinRangeOfSupportSpotSq = WithinRangeOfSupportSpot * WithinRangeOfSupportSpot;
		}
		/*
		ParamLoader() : iniFileLoaderBase("Params_Second.ini")
		{
		GoalWidth2 = GetNextParameterDouble();

		NumSupportSpotsX2 = GetNextParameterInt();
		NumSupportSpotsY2 = GetNextParameterInt();

		Spot_PassSafeScore2 = GetNextParameterDouble();
		Spot_CanScoreFromPositionScore2 = GetNextParameterDouble();
		Spot_DistFromControllingPlayerScore2 = GetNextParameterDouble();
		Spot_ClosenessToSupportingPlayerScore2 = GetNextParameterDouble();
		Spot_AheadOfAttackerScore2 = GetNextParameterDouble();

		SupportSpotUpdateFreq2 = GetNextParameterDouble();

		ChancePlayerAttemptsPotShot2 = GetNextParameterDouble();
		ChanceOfUsingArriveTypeReceiveBehavior2 = GetNextParameterDouble();

		BallSize2 = GetNextParameterDouble();
		BallMass2 = GetNextParameterDouble();
		Friction2 = GetNextParameterDouble();

		KeeperInBallRange2 = GetNextParameterDouble();
		PlayerInTargetRange2 = GetNextParameterDouble();
		PlayerKickingDistance2 = GetNextParameterDouble();
		PlayerKickFrequency2 = GetNextParameterDouble();


		PlayerMass2 = GetNextParameterDouble();
		PlayerMaxForce2 = GetNextParameterDouble();
		PlayerMaxSpeedWithBall2 = GetNextParameterDouble();
		PlayerMaxSpeedWithoutBall2 = GetNextParameterDouble();
		PlayerMaxTurnRate2 = GetNextParameterDouble();
		PlayerScale2 = GetNextParameterDouble();
		PlayerComfortZone2 = GetNextParameterDouble();
		PlayerKickingAccuracy2 = GetNextParameterDouble();

		NumAttemptsToFindValidStrike2 = GetNextParameterInt();



		MaxDribbleForce2 = GetNextParameterDouble();
		MaxShootingForce2 = GetNextParameterDouble();
		MaxPassingForce2 = GetNextParameterDouble();

		WithinRangeOfHome2 = GetNextParameterDouble();
		WithinRangeOfSupportSpot2 = GetNextParameterDouble();

		MinPassDist2 = GetNextParameterDouble();
		GoalkeeperMinPassDist2 = GetNextParameterDouble();

		GoalKeeperTendingDistance2 = GetNextParameterDouble();
		GoalKeeperInterceptRange2 = GetNextParameterDouble();
		BallWithinReceivingRange2 = GetNextParameterDouble();

		bStates2 = GetNextParameterBool();
		bIDs2 = GetNextParameterBool();
		bSupportSpots2 = GetNextParameterBool();
		bRegions2 = GetNextParameterBool();
		bShowControllingTeam2 = GetNextParameterBool();
		bViewTargets2 = GetNextParameterBool();
		bHighlightIfThreatened2 = GetNextParameterBool();

		FrameRate2 = GetNextParameterInt();

		SeparationCoefficient2 = GetNextParameterDouble();
		ViewDistance2 = GetNextParameterDouble();
		bNonPenetrationConstraint2 = GetNextParameterBool();


		BallWithinReceivingRangeSq2 = BallWithinReceivingRange * BallWithinReceivingRange;
		KeeperInBallRangeSq2 = KeeperInBallRange * KeeperInBallRange;
		PlayerInTargetRangeSq2 = PlayerInTargetRange * PlayerInTargetRange;
		PlayerKickingDistance2 += BallSize;
		PlayerKickingDistanceSq2 = PlayerKickingDistance * PlayerKickingDistance;
		PlayerComfortZoneSq2 = PlayerComfortZone * PlayerComfortZone;
		GoalKeeperInterceptRangeSq2 = GoalKeeperInterceptRange * GoalKeeperInterceptRange;
		WithinRangeOfSupportSpotSq2 = WithinRangeOfSupportSpot * WithinRangeOfSupportSpot;
		}*/

public:

  static ParamLoader* Instance();
  static ParamLoader* Instance2();

  double GoalWidth;

  int   NumSupportSpotsX;
  int   NumSupportSpotsY;

  //these values tweak the various rules used to calculate the support spots
  double Spot_PassSafeScore;
  double Spot_CanScoreFromPositionScore;
  double Spot_DistFromControllingPlayerScore;
  double Spot_ClosenessToSupportingPlayerScore;
  double Spot_AheadOfAttackerScore;  
  
  double SupportSpotUpdateFreq ;

  double ChancePlayerAttemptsPotShot; 
  double ChanceOfUsingArriveTypeReceiveBehavior;

  double BallSize;
  double BallMass;
  double Friction;

  double KeeperInBallRange;
  double KeeperInBallRangeSq;

  double PlayerInTargetRange;
  double PlayerInTargetRangeSq;
  
  double PlayerMass;
  
  //max steering force
  double PlayerMaxForce; 
  double PlayerMaxSpeedWithBall;
  double PlayerMaxSpeedWithoutBall;
  double PlayerMaxTurnRate;
  double PlayerScale;
  double PlayerComfortZone;

  double PlayerKickingDistance;
  double PlayerKickingDistanceSq;

  double PlayerKickFrequency; 

  double  MaxDribbleForce;
  double  MaxShootingForce;
  double  MaxPassingForce;

  double  PlayerComfortZoneSq;

  //in the range zero to 1.0. adjusts the amount of noise added to a kick,
  //the lower the value the worse the players get
  double  PlayerKickingAccuracy;

  //the number of times the SoccerTeam::CanShoot method attempts to find
  //a valid shot
  int    NumAttemptsToFindValidStrike;

  //the distance away from the center of its home region a player
  //must be to be considered at home
  double WithinRangeOfHome;

  //how close a player must get to a sweet spot before he can change state
  double WithinRangeOfSupportSpot;
  double WithinRangeOfSupportSpotSq;
 
  
  //the minimum distance a receiving player must be from the passing player
  double   MinPassDist;
  double   GoalkeeperMinPassDist;

  //this is the distance the keeper puts between the back of the net
  //and the ball when using the interpose steering behavior
  double  GoalKeeperTendingDistance;

  //when the ball becomes within this distance of the goalkeeper he
  //changes state to intercept the ball
  double  GoalKeeperInterceptRange;
  double  GoalKeeperInterceptRangeSq;

  //how close the ball must be to a receiver before he starts chasing it
  double  BallWithinReceivingRange;
  double  BallWithinReceivingRangeSq;


  //these values control what debug info you can see
  bool  bStates;
  bool  bIDs;
  bool  bSupportSpots;
  bool  bRegions;
  bool  bShowControllingTeam;
  bool  bViewTargets;
  bool  bHighlightIfThreatened;

  int FrameRate;

  
  double SeparationCoefficient;

  //how close a neighbour must be before an agent perceives it
  double ViewDistance;

  //zero this to turn the constraint off
  bool bNonPenetrationConstraint;






  double GoalWidth2;

  int   NumSupportSpotsX2;
  int   NumSupportSpotsY2;

  //these values tweak the various rules used to calculate the support spots
  double Spot_PassSafeScore2;
  double Spot_CanScoreFromPositionScore2;
  double Spot_DistFromControllingPlayerScore2;
  double Spot_ClosenessToSupportingPlayerScore2;
  double Spot_AheadOfAttackerScore2;

  double SupportSpotUpdateFreq2;

  double ChancePlayerAttemptsPotShot2;
  double ChanceOfUsingArriveTypeReceiveBehavior2;

  double BallSize2;
  double BallMass2;
  double Friction2;

  double KeeperInBallRange2;
  double KeeperInBallRangeSq2;

  double PlayerInTargetRange2;
  double PlayerInTargetRangeSq2;

  double PlayerMass2;

  //max steering force
  double PlayerMaxForce2;
  double PlayerMaxSpeedWithBall2;
  double PlayerMaxSpeedWithoutBall2;
  double PlayerMaxTurnRate2;
  double PlayerScale2;
  double PlayerComfortZone2;

  double PlayerKickingDistance2;
  double PlayerKickingDistanceSq2;

  double PlayerKickFrequency2;

  double  MaxDribbleForce2;
  double  MaxShootingForce2;
  double  MaxPassingForce2;

  double  PlayerComfortZoneSq2;

  //in the range zero to 1.0. adjusts the amount of noise added to a kick,
  //the lower the value the worse the players get
  double  PlayerKickingAccuracy2;

  //the number of times the SoccerTeam::CanShoot method attempts to find
  //a valid shot
  int    NumAttemptsToFindValidStrike2;

  //the distance away from the center of its home region a player
  //must be to be considered at home
  double WithinRangeOfHome2;

  //how close a player must get to a sweet spot before he can change state
  double WithinRangeOfSupportSpot2;
  double WithinRangeOfSupportSpotSq2;


  //the minimum distance a receiving player must be from the passing player
  double   MinPassDist2;
  double   GoalkeeperMinPassDist2;

  //this is the distance the keeper puts between the back of the net
  //and the ball when using the interpose steering behavior
  double  GoalKeeperTendingDistance2;

  //when the ball becomes within this distance of the goalkeeper he
  //changes state to intercept the ball
  double  GoalKeeperInterceptRange2;
  double  GoalKeeperInterceptRangeSq2;

  //how close the ball must be to a receiver before he starts chasing it
  double  BallWithinReceivingRange2;
  double  BallWithinReceivingRangeSq2;


  //these values control what debug info you can see
  bool  bStates2;
  bool  bIDs2;
  bool  bSupportSpots2;
  bool  bRegions2;
  bool  bShowControllingTeam2;
  bool  bViewTargets2;
  bool  bHighlightIfThreatened2;

  int FrameRate2;


  double SeparationCoefficient2;

  //how close a neighbour must be before an agent perceives it
  double ViewDistance2;

  //zero this to turn the constraint off
  bool bNonPenetrationConstraint2;

};

#endif